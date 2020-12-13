/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;
int main() {
  string s, qaq = "QAQ";
  int dp[3][100];
  memset(dp, -1, sizeof(dp));
  cin >> s;
  function<int(int,int)> findQAQ = [&](int k, int i) {
    if (k == 3) return 1;
    if (i == s.size()) return 0;
    int &ret = dp[k][i];
    if (ret != -1) return ret;
    ret = findQAQ(k, i+1);
    if (s[i]==qaq[k])
      ret += findQAQ(k+1, i+1);
    return ret;
  };
  cout << findQAQ(0,0);
}
