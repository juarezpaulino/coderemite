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
  int n; cin >> n;
  vector<int> a(n);
  for (int &u: a) cin >> u;
  sort(begin(a), end(a));
  long long ret = 0;
  for (int i = 0; i < n; i++) ret += (i+2LL)*a[i];
  ret -= a[n-1];
  cout << ret;
} 
