/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int s, n;
  cin >> s >> n;
  vector<pair<int,int>> x(n);
  for (auto &u: x) cin >> u.first >> u.second;
  sort(begin(x), end(x));
  for (auto &u: x) {
    if (s <= u.first) {
      cout << "NO" << endl;
      return 0;
    }
    s += u.second;
  }
  cout << "YES";
}
