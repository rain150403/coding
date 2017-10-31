//转自：http://blog.csdn.net/l773575310/article/details/68943208

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

//物品结构体,重量,价值,是否被选中
struct Item
{
    int Wi = 0;
    int Vi = 0;
    bool selected = false;
};

//存放物品的容器,这里偷懒就用全局变量了
vector<Item> vecItem;

int dp[200][5001];

//核心函数,获取最大价值
int getMaxValue(int itemsSize, int maxWeight);

//修改选中物品的选中状态
void findSelectedItems(int itemsSize, int maxWeight);

int main()
{
    int n, maxW;
    //输入物品数,背包承重
    cin >> n >> maxW;
    for (size_t i = 0; i < n; ++i)
    {
        Item item;
        cin >> item.Wi >> item.Vi;
        //这里简单优化,将物品大于背包承重直接排除,但注意后面物品总数量就为vecItem.size()而不是n了.
        if (item.Wi <= maxW)
            vecItem.push_back(item);
    }

    //获取最大价值
    int maxValue = getMaxValue(vecItem.size(), maxW);

    //找到最大价值下的选中物品,并修改物品选中状态
    findSelectedItems(vecItem.size(), maxW);

    cout << "max value :" << maxValue <<endl <<"selected items :"<<endl;
    for (size_t i = 0; i < vecItem.size(); ++i)
    {
        if (vecItem[i].selected)
            cout <<"index "<< i << " : "<< vecItem[i].Wi << " - " << vecItem[i].Vi << endl;
    }

    system("pause");
    return 0;
}

int getMaxValue(int itemsSize, int maxWeight)
{
    //从下到上,左到右遍历
    for (int j = 1; j <= maxWeight; ++j)
    {
        //为了避免下面循环越界,这里直接处理最后一行的值,因为只有一个物品,所以知道物品重量不大于背包,就直接赋值就好了
        if (vecItem[itemsSize - 1].Wi <= j)
            dp[itemsSize - 1][j] = vecItem[itemsSize - 1].Vi;
        for (int i = itemsSize - 2; i >= 0; --i)
        {
            //这里就是状态转换方程了
            if (j < vecItem[i].Wi)
                dp[i][j] = dp[i + 1][j];
            else
                dp[i][j] = max(dp[i + 1][j - vecItem[i].Wi] + vecItem[i].Vi, dp[i + 1][j]);
        }
    }
    return dp[0][maxWeight];
}

void findSelectedItems(int itemsSize, int maxWeight)
{
    //从dp右上角开始,从上到下,从右到左遍历,i到最后一个物品结束
    int k = maxWeight;
    for (int i = 0; i < itemsSize; ++i)
    {
        if (dp[i][k]>dp[i + 1][k])
        {
            vecItem[i].selected = true;
            k -= vecItem[i].Wi;
        }
    }
}
