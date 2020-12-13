/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(m);
  for (int &u: a) cin >> u;
  int x; cin >> x;
  int ret = 0;
  for (int &u: a) if (__builtin_popcount(u^x) <= k) ret++;
  cout << ret;
} 
