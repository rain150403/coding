/*
//转自：https://liam0205.me/2016/01/31/binomial-in-cpp/

在 Python 中，标准库 itertools 提供了排列、组合、笛卡尔积的方法。然而在 C++ 中，标准库只提供了 next_permutation 和 prev_permutation，通常来说
不太够用。

这里，我们给出两种思路的算法。
*/

//二进制辅助的方法

/*
二进制辅助的方法
我们先来讨论一下非递归的方法。

对于组合来说，对每个元素是否选取，只有「选」和「不选」两种状态。因此，我们可以用一串二进制，来表示「选与不选」。例如：10110 表示五选三时，第一位、
第三位和第四位被选择，剩下两位则不选。

接下来，我们要非重复、不遗漏地找到所有可能的组合方式，就有必要找到某种顺序。这种顺序应该满足：

不重复
不遗漏
有某种可以观察的良好性质
在计算机上容易实现

不难想到，如果我们以二进制来表示一种组合状态，那么它就对应着一个十进制数。比如五选三时，就是要求解五位二进制数中，有三个数位是 1 的全部可能性。要不
重复不遗漏地找出这些可能性，我们可以很简单地定义这样的顺序：找到满足五位二进制数中有三个数位是 1 的数字的升序排列。
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string>& combination(vector<string>& res, const size_t& choose, const size_t& from);
bool compare (const char& lhs, const char& rhs);

int main () {
  vector<string> res;
  int c, f;
  scanf( "%d%d", &c, &f );
  const size_t choose = c, from = f;
  combination (res, choose, from);
  for (size_t i = 0; i != res.size(); ++i) {
    cout << res[i] << '\t';
    for (size_t j = 0; j != from; ++j) {
      if (res[i][j] == '1') {
        cout << j + 1 << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}
vector<string>& combination(vector<string>& res, const size_t& choose, const size_t& from) {
  string wk = string (choose, '1') + string (from - choose, '0');
  res.push_back (wk);
  size_t found = string::npos;
  while ((found = wk.find("10")) != string::npos) {
    // 1. swap found
    wk[found] ^= wk[found + 1];
    wk[found + 1] ^= wk[found];
    wk[found] ^= wk[found + 1];
    // 2. sort before
    sort (wk.begin(), wk.begin() + found, compare);
    res.push_back (wk);
  }
  return res;
}
bool compare (const char& lhs, const char& rhs) {
  return lhs > rhs;
}



//平凡的递归解法（根据组合递推关系）

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string>& combination (vector<string>& res, const size_t& choose, string& working, const size_t& pos);

int main () {
  vector<string> res;
  int c, f;
  scanf( "%d%d", &c, &f );
  const size_t choose = c;
  string working (f, '0');
  combination (res, choose, working, 0);
  for (size_t i = 0; i != res.size(); ++i) {
    cout << res[i] << '\t';
    for (size_t j = 0; j != working.size(); ++j) {
      if (res[i][j] == '1') {
        cout << j + 1 << ' ';
      }
    }
    cout << endl;
  }
  return 0;
}

vector<string>& combination (vector<string>& res, const size_t& choose, string& working, const size_t& pos) {
  if (choose > working.size() - pos) return res;
  for (size_t i = pos; i != working.size(); ++i) {
    working[i] = '0';
  }
  if (choose == 0 || pos == working.size()) {
    res.push_back (working);
    return res;
  }
  working[pos] = '1';
  combination (res, choose - 1, working, pos + 1);
  working[pos] = '0';
  combination (res, choose, working, pos + 1);
  return res;
}


//还有一种方式是回溯法求排列组合，以后好好看
