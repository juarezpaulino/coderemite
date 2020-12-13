/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int k, v[10];
ll dp[11][11];

ll perfectLess(int d, int s, int cur) {
  if (!d) return s==10 ? 1LL : 0LL;
  if (!cur && dp[d][s]!=-1) return dp[d][s];
  ll ret = 0;
  int lim = (cur) ? v[d] : 9;
  lim = min(lim, 10-s);
  for (int i = 0; i <= lim; i++)
    ret += perfectLess(d-1, s+i, cur&&(i==v[d]));
  if (!cur) dp[d][s] = ret;
  return ret;
};
  
bool check(int u) {
  int d = 0, z = u;
  while (u) { v[++d] = u%10; u/=10; }
  memset(dp, -1, sizeof(dp));
  return perfectLess(d,0,1) >= k;
}

int main() {
  cin >> k;
  int lo = 19, hi = 100000000;
  while (lo < hi) {
    int m = lo + (hi-lo)/2;
    check(m) ? hi = m : lo = m+1;
  }
  cout << hi;
}
