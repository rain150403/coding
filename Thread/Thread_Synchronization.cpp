线程同步：同步各个线程对资源（比如全局变量、文件）的访问。
同步方式：临界区对象、互斥对象、事件对象、信号量。


线程不同步的例子：
    模拟这样一个场景，甲乙两个窗口在售票，一共10张票，每张票的号码不同，每卖出一张票，就打印出卖出票的票号，我们可以开辟两个线程当作两个窗口卖票，
    如果线程没有同步，可能会出现两个窗口卖出的票是相同的，这就发生了错误。
    
//8-11 不同线程同步的卖票程序

#include "windows.h"
#include <stdio.h>
#include <tchar.h>
#include <strsafe.h>    //字符串处理函数无须

#define BUF_SIZE 100

int gticketID = 10;  //当前卖出票的票号

DWORD WINAPI threadfunc(LPVOID param){
	HANDLE hStdout;
	DWORD i, dwChars;
	size_t szlen;
	TCHAR chWin, msgBuf[BUF_SIZE];

	if (param == 0) chWin = _T('甲');   //甲窗口
	else chWin = _T('乙');  //乙窗口

	while (1){
		if (gticketID <= 0)    //如果票号小于等于零，则跳出循环
			break;
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);   //得到标准输出设备的句柄，为了打印
		if (hStdout == INVALID_HANDLE_VALUE){
			return 1;
		}
		//构造字符串
		StringCchPrintf(msgBuf, BUF_SIZE, _T("%c窗口卖出的车票号 = %d\n"), chWin, gticketID);
		StringCchLength(msgBuf, BUF_SIZE, &szlen);   //得到字符串长度

		WriteConsole(hStdout, msgBuf, szlen, &dwChars, NULL);
		gticketID--;   //每卖出一张车票，车票就减少一张
	}
}

int _tmain(int argc, _TCHAR* argv[]){
	int i;
	HANDLE h[2];

	for (i = 0; i < 2; i++)
		h[i] = CreateThread(NULL, 0, threadfunc, (LPVOID)i, 0, 0);
	for (i = 0; i < 2; i++){
		WaitForSingleObject(h[i], INFINITE);
		CloseHandle(h[i]);
	}
	printf("卖票结束\n");
	system("pause");
	return 0;
}


临界区对象通过一个所有线程共享的对象来实现线程同步。
线程要访问被临界区对象保护的资源，必须先要拥有该临界区对象。
如果另一个线程要访问资源，则必须等待上一个访问资源的线程释放临界区对象。
临界区对象只能用于一个进程内的不同线程之间的同步。

临界区的意思是一段关键代码，执行代码相当于进入临界区。

操作临界区对象的函数：
1）InitializeCriticalSection函数
初始化一个临界区对象。
2）EnterCriticalSection函数
等待临界区对象的所有权，如果能获得临界区对象则该函数返回，否则函数进入阻塞，线程进入睡眠状态，一直到拥有临界区对象的线程释放临界区对象。
3）TryEnterCriticalSection函数
等待临界区对象的所有权，和上个函数不同的是，函数不管有没有获得临界区对象所有权，都将立即返回，相当于一个异步函数。
4）LeaveCriticalSection函数
释放临界区对象的所有权。
5）DeleteCriticalSection函数
删除临界区对象，释放相关资源，使得临界区对象不再可用。

//例8-12 使用临界区对象同步线程

#include "stdafx.h"
#include "windows.h"
#include <tchar.h>
#include <strsafe.h>

#define BUF_SIZE 100  //输出缓冲区大小
int gticketId = 10;   //记录卖出的车票号
CRITICAL_SECTION gcs;   //定义临界区对象

DWORD WINAPI threadfunc(LPVOID param){
	HANDLE hStdout;
	DWORD i, dwChars;
	size_t szlen;
	TCHAR chWin, msgBuf[BUF_SIZE];

	if (param == 0) chWin = _T('甲'); //甲窗口
	else chWin = _T('乙'); //乙窗口
	while (1){
		EnterCriticalSection(&gcs);
		if (gticketId <= 0)
		{
			LeaveCriticalSection(&gcs);   //注意要释放临界区对象所有权
			break;
		}
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);   //得到标准输出设备的句柄，为了打印
		if (hStdout == INVALID_HANDLE_VALUE){
			LeaveCriticalSection(&gcs);   //注意要释放临界区对象所有权
			return 1;
		}
		构造字符串
		StringCchPrintf(msgBuf, BUF_SIZE, _T("%c窗口卖出的车票号 = %d\n"), chWin, gticketId);
		StringCchLength(msgBuf, BUF_SIZE, &szlen);    //得到字符串长度

		WriteConsole(hStdout, msgBuf, szlen, &dwChars, NULL);  //在终端打印车票号
		gticketId--;  //车票减少一张
		LeaveCriticalSection(&gcs);   //释放临界区对象所有权
		Sleep(1);  //让出CPU，让另外一个线程有机会执行
	}
}

int _tmain(int argc, _TCHAR* argv[]){
	int i;
	HANDLE h[2];

	InitializeCriticalSection(&gcs);  //初始化临界区对象

	for (i = 0; i < 2; i++)
		h[i] = CreateThread(NULL, 0, threadfunc, (LPVOID)i, 0, 0);  //开辟两个线程
	for (i = 0; i < 2; i++){
		WaitForSingleObject(h[i], INFINITE);   //等待线程结束
		CloseHandle(h[i]);   //关闭线程对象句柄
	}

	DeleteCriticalSection(&gcs);  //删除临界区对象
	printf("卖票结束\n");

	system("pause");
	return 0;
}




//例8-13 使用互斥对象同步线程

//#include "stdafx.h"
#include "windows.h"
#include <tchar.h>
#include <strsafe.h>

#define BUF_SIZE 100  //输出缓冲区大小
int gticketId = 10;   //记录卖出的车票号
HANDLE ghMutex;   //互斥对象句柄


DWORD WINAPI threadfunc(LPVOID param){
	HANDLE hStdout;
	DWORD i, dwChars;
	size_t szlen;
	TCHAR chWin, msgBuf[BUF_SIZE];

	if (param == 0) chWin = _T('甲'); //甲窗口
	else chWin = _T('乙'); //乙窗口
	while (1){
		WaitForSingleObject(ghMutex, INFINITE); //等待互斥对象有信号
		if (gticketId <= 0)   //如果车票全部卖出了，则退出循环
		{
			ReleaseMutex(ghMutex);  //释放互斥对象所有权
			break;
		}
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);   //得到标准输出设备的句柄，为了打印
		if (hStdout == INVALID_HANDLE_VALUE){
			ReleaseMutex(ghMutex);  //释放事件对象所有权
			return 1;
		}
		//构造字符串
		StringCchPrintf(msgBuf, BUF_SIZE, _T("%c窗口卖出的车票号 = %d\n"), chWin, gticketId);
		StringCchLength(msgBuf, BUF_SIZE, &szlen);

		WriteConsole(hStdout, msgBuf, szlen, &dwChars, NULL);  //控制台输出
		gticketId--;  //车票减少一张
		ReleaseMutex(ghMutex); //释放互斥对象所有权
		//Sleep(1);  //这句可以不用了
	}
}

int _tmain(int argc, _TCHAR* argv[]){
	int i;
	HANDLE h[2];

	printf("使用互斥对象同步线程\n");
	ghMutex = CreateMutex(NULL, FALSE, _T("myMutex"));    //创建互斥对象

	for (i = 0; i < 2; i++)
		h[i] = CreateThread(NULL, 0, threadfunc, (LPVOID)i, 0, 0);  //创建线程
	for (i = 0; i < 2; i++){
		WaitForSingleObject(h[i], INFINITE);   //等待线程结束
		CloseHandle(h[i]);   //关闭线程对象句柄
	}

	CloseHandle(ghMutex);   //关闭互斥对象句柄
	printf("卖票结束\n");

	system("pause");
	return 0;
}



//例8-14 使用事件对象同步线程

//#include "stdafx.h"
#include "windows.h"
#include <tchar.h>
#include <strsafe.h>

#define BUF_SIZE 100  //输出缓冲区大小
int gticketId = 10;   //记录卖出的车票号
HANDLE ghEvent;   //事件对象句柄


DWORD WINAPI threadfunc(LPVOID param){
	HANDLE hStdout;
	DWORD i, dwChars;
	size_t szlen;
	TCHAR chWin, msgBuf[BUF_SIZE];

	if (param == 0) chWin = _T('甲'); //甲窗口
	else chWin = _T('乙'); //乙窗口
	while (1){
		WaitForSingleObject(ghEvent, INFINITE); //等待事件对象有信号
		if (gticketId <= 0)   //如果车票全部卖出了，则退出循环
		{
			SetEvent(ghEvent);  //设置事件对象有信号
			break;
		}
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);   //得到标准输出设备的句柄，为了打印
		if (hStdout == INVALID_HANDLE_VALUE){
			SetEvent(ghEvent);  //释放事件对象所有权
			return 1;
		}
		//构造字符串
		StringCchPrintf(msgBuf, BUF_SIZE, _T("%c窗口卖出的车票号 = %d\n"), chWin, gticketId);
		StringCchLength(msgBuf, BUF_SIZE, &szlen);

		WriteConsole(hStdout, msgBuf, szlen, &dwChars, NULL);  //控制台输出
		gticketId--;  //车票减少一张
		SetEvent(ghEvent);  //设置事件对象有信号
		//Sleep(1);  //这句可以不用了
	}
}

int _tmain(int argc, _TCHAR* argv[]){
	int i;
	HANDLE h[2];
	printf("使用事件对象同步线程\n");
	ghEvent = CreateEvent(NULL, FALSE, TRUE, _T("myEvent"));    //创建事件对象

	for (i = 0; i < 2; i++)
		h[i] = CreateThread(NULL, 0, threadfunc, (LPVOID)i, 0, 0);  //创建线程
	for (i = 0; i < 2; i++){
		WaitForSingleObject(h[i], INFINITE);   //等待线程结束
		CloseHandle(h[i]);   //关闭线程对象句柄
	}

	CloseHandle(ghEvent);   //关闭事件对象句柄
	printf("卖票结束\n");

	system("pause");
	return 0;
}




//例8-15 使用信号量对象同步线程

//#include "stdafx.h"
#include "windows.h"
#include <tchar.h>
#include <strsafe.h>

#define BUF_SIZE 100  //输出缓冲区大小
int gticketId = 10;   //记录卖出的车票号
HANDLE ghSemaphore;   //信号量对象句柄


DWORD WINAPI threadfunc(LPVOID param){
	HANDLE hStdout;
	DWORD i, dwChars;
	size_t szlen;
	LONG cn;
	TCHAR chWin, msgBuf[BUF_SIZE];

	if (param == 0) chWin = _T('甲'); //甲窗口
	else chWin = _T('乙'); //乙窗口
	while (1){
		WaitForSingleObject(ghSemaphore, INFINITE); //等待信号量对象有信号
		if (gticketId <= 0)   //如果车票全部卖出了，则退出循环
		{
			ReleaseSemaphore(ghSemaphore, 1, &cn);  //释放信号量对象所有权
			break;
		}
		hStdout = GetStdHandle(STD_OUTPUT_HANDLE);   //得到标准输出设备的句柄，为了打印
		if (hStdout == INVALID_HANDLE_VALUE){
			ReleaseSemaphore(ghSemaphore, 1, &cn);   //释放信号量对象所有权
			return 1;
		}
		//构造字符串
		StringCchPrintf(msgBuf, BUF_SIZE, _T("%c窗口卖出的车票号 = %d\n"), chWin, gticketId);
		StringCchLength(msgBuf, BUF_SIZE, &szlen);

		WriteConsole(hStdout, msgBuf, szlen, &dwChars, NULL);  //控制台输出
		gticketId--;  //车票减少一张
		ReleaseSemaphore(ghSemaphore, 1, &cn);  //释放信号量对象所有权
		//Sleep(1);  //这句可以不用了
	}
}

int _tmain(int argc, _TCHAR* argv[]){
	int i;
	HANDLE h[2];
	printf("使用信号量对象同步线程\n");
	ghSemaphore = CreateSemaphore(NULL, 1, 50, _T("mySemaphore"));    //创建信号量对象

	for (i = 0; i < 2; i++)
		h[i] = CreateThread(NULL, 0, threadfunc, (LPVOID)i, 0, 0);  //创建线程
	for (i = 0; i < 2; i++){
		WaitForSingleObject(h[i], INFINITE);   //等待线程结束
		CloseHandle(h[i]);   //关闭线程对象句柄
	}

	CloseHandle(ghSemaphore);   //关闭信号量对象句柄
	printf("卖票结束\n");
	system("pause");
	return 0;
}
