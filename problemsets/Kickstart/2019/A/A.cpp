/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int solve() {
  int n, p; cin >> n >> p;
  vector<int> a(n);
  for (int &u: a) cin >> u;
  sort(begin(a), end(a));
  int ret = INT_MAX, cur = 0;
  for (int i = 1; i < n; i++) {
    cur += (a[i]-a[i-1]) * min(p, i);
    if (i >= p)  cur -= a[i]-a[i-p];
    if (i >= p-1) ret = min(ret, cur);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  int t; cin >> t;
  for (int i = 1; i <= t; i++)
    cout << "Case #" << i << ": " << solve() << endl;
}