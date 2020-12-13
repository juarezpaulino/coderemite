/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    bool ok = 0;
    for (int i = 1; i < a.size(); i++)
      if (a[i] != a[i-1]) {
        if (a[i] < a[i-1]) swap(a[i],a[i-1]);
        ok = 1;
      }
    cout << (ok ? a : "-1") << endl;
  }
}
