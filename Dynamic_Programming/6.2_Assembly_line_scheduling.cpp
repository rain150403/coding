//转自：http://www.cnblogs.com/mengwang024/p/4295389.html

#include <iostream>
using namespace std;

typedef struct  
{
    int **a;
    int **t;
    int *e;
    int *x;
    int n;
}LineCondition;

void FastestWay(const LineCondition *line, int **&l, int **&f, int &ftotal, int &lend)
{
    int n = line->n;

    f[0][0] = line->e[0] + line->a[0][0];
    f[1][0] = line->e[1] + line->a[1][0];

    for (int i = 1; i < n; ++i)
    {
        if (f[0][i - 1] + line->a[0][i] <= f[1][i - 1] + line->t[1][i - 1] + line->a[0][i])
        {
            f[0][i] = f[0][i - 1] + line->a[0][i];
            l[0][i] = 1;
        }
        else
        {
            f[0][i] = f[1][i - 1] + line->t[1][i - 1] + line->a[0][i];
            l[0][i] = 2;
        }

        if (f[1][i - 1] + line->a[1][i] <= f[0][i - 1] + line->t[0][i - 1] + line->a[1][i])
        {
            f[1][i] = f[1][i - 1] + line->a[1][i];
            l[1][i] = 2;
        }
        else
        {
            f[1][i] = f[0][i - 1] + line->t[0][i - 1] + line->a[1][i];
            l[1][i] = 1;
        }
    }

    if (f[0][n - 1] + line->x[0] <= f[1][n - 1] + line->x[1])
    {
        ftotal = f[0][n - 1] + line->x[0];
        lend = 1;
    }
    else
    {
        ftotal = f[1][n - 1] + line->x[1];
        lend = 2;
    }
}

void PrintStations(int **l, int lend, int n)
{
    int *a = new int[n];
    int i = lend - 1;
    int m = n;
    a[--m] = i + 1;

    for (int j = n - 1; j > 0; --j)
    {
        i = l[i][j] - 1;
        a[--m] = i + 1;
    }

    for (int i = 0; i < n; ++i)
    {
        cout << "line " << a[i] << ", station " << i + 1 << endl;
    }
    
    delete [] a;
}


int main(void)
{
    LineCondition line;

    cout << "请输入装配站数目n:";
    cin >> line.n;

    line.a = new int *[2];
    for (int i = 0; i < 2; ++i)
    {
        line.a[i] = new int [line.n];
    }
    for (int i = 0; i < 2; ++i)
    {
        cout << "请输入装配线" << i + 1 << "上每个装配站耗费时间a[i][j]:";
        for (int j = 0; j < line.n; ++j)
        {
            cin >> line.a[i][j];
        }
    }

    line.t = new int *[2];
    for (int i = 0; i < 2; ++i)
    {
        line.t[i] = new int [line.n - 1];
    }
    for (int i = 0; i < 2; ++i)
    {
        cout << "请输入装配线t[" << i << "][j]:";
        for (int j = 0; j < line.n - 1; ++j)
        {
            cin >> line.t[i][j];
        }
    }

    line.e = new int [2];
    cout << "请输入e1,e2:";
    cin >> line.e[0] >> line.e[1];

    line.x = new int [2];
    cout << "请输入x1,x2:";
    cin >> line.x[0] >> line.x[1];

    int **l = new int *[2];
    int **f = new int *[2];
    for (int i = 0; i < 2; ++i)
    {
        l[i] = new int [line.n];
        f[i] = new int [line.n];
    }

    int lend, ftotal;
    FastestWay(&line, l, f, ftotal, lend);
    PrintStations(l, lend, line.n);

    return 0;
}
