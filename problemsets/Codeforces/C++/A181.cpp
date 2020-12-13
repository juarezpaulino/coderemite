/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

#define mt make_tuple

int main() {
  int n, m, y1, y2, x1, x2;
  cin >> n >> m;
  tie(y1,x1,y2,x2) = mt(1e8,1e8,-1,-1);
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < m; j++) if (a[i][j]=='*')
      y1 = min(y1, i),
      x1 = min(x1, j),
      y2 = max(y2, i),
      x2 = max(x2, j);
  }
  int y, x;
  tie(y,x) = (a[y1][x1]=='.'?mt(y1,x1):a[y1][x2]=='.'?mt(y1,x2):a[y2][x1]=='.'?mt(y2,x1):mt(y2,x2));
  cout << y+1 << " " << x+1;
}
