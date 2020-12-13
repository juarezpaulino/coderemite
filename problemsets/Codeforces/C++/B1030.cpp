/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int d, n, m;  cin >> n >> d >> m;
  while (m--) {
    int x, y; cin >> x >> y;
    int y1 = (x <= d) ? d-x : x-d;
    int w = min(d, n-d);
    int d1 = (x <= w) ? x : (x >= n-w) ? n-x : w;
    cout << (y1 <= y && y <= y1+2*d1 ? "YES" : "NO") << endl;
  }
}
