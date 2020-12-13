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
  vector<string> a(n); for (auto &u: a) cin >> u;
  sort(begin(a), end(a), [](string &a, string &b){ return a.size() < b.size(); });
  for (int i = 0; i < n; i++) if (i < n-1 && a[i+1].find(a[i]) == -1) {
    cout << "NO"; return 0;
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; i++) cout << a[i] << endl;
}
