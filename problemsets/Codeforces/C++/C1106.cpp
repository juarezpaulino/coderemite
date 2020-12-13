/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int &u: a) cin >> u;
  sort(begin(a), end(a));
  long long ret = 0;
  auto sqr = [](int u){return u*u;};
  for (int i = 0; i < n/2; i++) ret += sqr(a[i]+a[n-i-1]);
  cout << ret;
}
