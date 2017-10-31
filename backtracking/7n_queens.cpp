//皇后问题

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

// 棋盘的横坐标是x，纵坐标是y。
// 横、纵、左斜、右斜四个方向可以用四个一次函数表示
// 对于坐标[i,j ]对应的四条线分别是：
// 横线可以用x=i [0,n-1]
// 纵线是y=j [0,n-1]
// 反斜线是x-y=i-j [-n+1,n-1]
// 正斜线是x+y=i+j [0,2n-2]
// 因此用四个数组可以表示这棋盘上所有被杀点, 在实现时为了方便可以用一个长度为6n-2的数组来存储

class ChessBoard {
public:
    bool* kill;  // x,y,x-y,x+y分别对应区段为[0,n)[n,2n)[2n,4n-1)[4n,6n-1)
    int n;
    ChessBoard(int N) : kill(NULL), n(N) {
        kill = new bool[6*N];
        for (int i = 0; i < 6*N; i++) {
            kill[i] = false;
        }
    }
    ~ChessBoard() {
        delete[] kill;
    }

    vector<int> four_lines(int i, int j) {
        vector<int> l;
        l.push_back(i);
        l.push_back(n + j);
        l.push_back(2 * n + i -j + n -1);
        l.push_back(4 * n + i + j);
        return l;
    }

    void add(int i, int j) {
        vector<int> pos = four_lines(i, j);
        for (int k = 0; k < 4; k++) {
            kill[pos[k]] = true;
        }
    }

    void del(int i, int j) {
        vector<int> pos = four_lines(i, j);
        for (int k = 0; k < 4; k++) {
            kill[pos[k]] = false;
        }
    }

    bool valid(int i, int j) {
        vector<int> pos = four_lines(i, j);
        for (int k = 0; k < 4; k++) {
            if (kill[pos[k]]) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        ChessBoard cb(n);
        vector<int> ans; // 第i个元素存储第i+1行的列号
        ans.push_back(0);
        cb.add(0, 0);
        //cout << "start i=0 j=0" << endl;
        while (!ans.empty()) {
            if (tryNQueens(cb, ans)) {  // 在一个有效的部分布局下填充下一个行
                if (ans.size() == cb.n) {
                    fill(ret, ans);
                    move_next(cb, ans);
                }
            } else {
                move_next(cb, ans);
            }
        }
        return ret;
    }

    void move_next(ChessBoard& cb, vector<int>& ans) {
        if (ans.size() == 0) { return ;}
        while (ans.size() != 0) {
            int i = ans.size() - 1;
            int j = ans.back();
            ans.pop_back();
            cb.del(i, j);
            j++;
            for (; j < cb.n; j++) {
                if (cb.valid(i, j)) {
                    ans.push_back(j);
                    cb.add(i, j);
                    //cout << "move next pos: i=" << i << " j=" << j << endl;
                    return ;
                }
            }
            //cout << "rool back row=" << ans.size() << endl;
        }
        return ;
    }

    bool tryNQueens(ChessBoard& cb, vector<int>& ans) {
        if (ans.size() == cb.n) {
            return true;
        }
        int i = ans.size();
        for (int j = 0; j < cb.n; j++) {
            if (cb.valid(i, j)) {
                ans.push_back(j);
                cb.add(i, j);
                //cout << "try next row: i=" << i << " j=" << j << endl;
                return true;;
            }
        }
        //cout << "try fail, i=" << i << endl;
        return false;
    }

    void fill(vector<vector<string>>& ret, vector<int>& ans) {
        //cout << "[Find]" << endl;
        string temp;
        for (int i = 0; i < ans.size(); i++) {
            temp += ".";
        }
        vector<string> str_ans;
        for (int i = 0; i < ans.size(); i++) {
            string s = temp;
            s[ans[i]] = 'Q';
            str_ans.push_back(s);
            //cout << s << endl;
        }
        ret.push_back(str_ans);
        return ;
    }

};

int main(){
    int n;
    scanf("%d", &n);
    vector<vector<string>> result;
    result = Solution().solveNQueens(n);
    int len = result.size();
    int len2 = result[0].size();
    for( int i = 0; i < len; i++ ){
        for( int j = 0; j < len2; j++ ){
            cout << result[i][j];
            cout << endl;
        }
        cout << endl;
    }
    //cout << endl;

    return 0;
}


// n皇后问题
