/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &u: a) cin >> u;
  sort(begin(a), end(a));
  for (int &u: a) cout << u << " ";
}
