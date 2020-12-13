/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  int n, d; cin >> n >> d;
  int p = 0, l = p+d, next = -1;
  string a; cin >> a;
  int ret = 0;
  for (int i = 1; i < n; i++) {
    if (a[i]=='1') next = i;
    if (i == l || i == n-1) {
      if (next == -1) { cout << "-1"; return 0; }
      ret++; l = next+d; p = next; next = -1;
    }
  }
  cout << ret;
}