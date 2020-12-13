/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int solve() {
  int n; cin >> n;
  string a; cin >> a;
  vector<int> sum(n+1, 0);
  int k = (n+1)/2;
  for (int i = 1; i <= n; i++)
    sum[i] = sum[i-1]+a[i-1]-'0';
  int ret = INT_MIN;
  for (int i = k; i <= n; i++)
    ret = max(ret, sum[i]-sum[i-k]);
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  int t; cin >> t;
  for (int i = 1; i <= t; i++) 
    cout << "Case #" << i << ": " << solve() << endl;
}