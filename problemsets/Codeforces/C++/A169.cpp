/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, p, v;
  cin >> n >> p >> v;
  vector<int> a(n);
  for (int &u: a) cin >> u;
  sort(begin(a), end(a));
  cout << a[v]-a[v-1];
}
