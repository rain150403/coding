/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements
initialized in A and B are m andn respectively.

混合插入有序数组，由于两个数组都是有序的，所有只要按顺序比较大小即可。最先想到的方法是建立一个m+n大小的新数组，然后逐个从A和B数组中取出元素比较，把较小
的加入新数组，然后在考虑A数组有剩余和B数组有剩余的两种情况，最后在把新数组的元素重新赋值到A数组中即可。代码如下：
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (m <= 0 && n <= 0) return;
        int a = 0, b = 0;
        int C[m + n];
        for (int i = 0; i < m + n; ++i) {
            if (a < m && b < n) {
                if (A[a] < B[b]) {
                    C[i] = A[a];
                    ++a;
                }
                else {
                    C[i] = B[b];
                    ++b;
                }
            }
            else if (a < m && b >= n) {
                C[i] = A[a];
                ++a;
            }
            else if (a >= m && b < n) {
                C[i] = B[b];
                ++b;
            }
            else return;
        }
        for (int i = 0; i < m + n; ++i) A[i] = C[i];
    }
};


//方法二
/*
这样固然没错，但是还有更简洁的方法，而且不用申请新变量。算法思想是：由于合并后A数组的大小必定是m+n，所以从最后面开始往前赋值，先比较A和B中最后一个元
素的大小，把较大的那个插入到m+n-1的位置上，再依次向前推。如果A中所有的元素都比B小，那么前m个还是A原来的内容，没有改变。如果A中的数组比B大的，当A循
环完了，B中还有元素没加入A，直接用个循环把B中所有的元素覆盖到A剩下的位置。代码如下:
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int count = m + n - 1;
        --m; --n;
        while (m >= 0 && n >= 0) A[count--] = A[m] > B[n] ? A[m--] : B[n--];
        while (n >= 0) A[count--] = B[n--];
    }
};
