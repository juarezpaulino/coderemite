/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
  int dy[] = { -1, 0, 1, 0 };
  int dx[] = { 0, -1, 0, 1 };
  int r, c; scanf("%d %d ", &r, &c);
  vector<string> F = vector<string>(r+10, string(c+10, '.'));
  for (int i = 1; i <= r; i++) cin >> &F[i][1];
  auto check = [&](int y, int x) {
    for (int i = 0; i < 4; i++)
      if (F[y+dy[i]][x+dx[i]] == 'S') return 0;
    return 1;
  };
  auto dog = [&](int y, int x) {
    for (int i = 0; i < 4; i++) {
      char &c = F[y+dy[i]][x+dx[i]];
      if (c == '.') c = 'D';
    }
  };
  for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++)
    if (F[i][j]=='W') { if (!check(i,j)) { cout << "No"; return 0; } }
    else if (F[i][j]=='S') dog(i,j);
  cout << "Yes" << endl;
  for (int i = 1; i <= r; i++) cout << F[i].substr(1,c) << endl;
}
