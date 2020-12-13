/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int solve() {
  int r, c; cin >> r >> c;
  string a;
  auto d = vector<vector<int>>(r, vector<int>(c, INT_MAX));
  queue<pair<int,int>> q;
  for (int i = 0; i < r; i++) {
    cin >> a;
    for (int j = 0; j < c; j++)
      if (a[j]=='1')
        d[i][j] = 0, q.push(make_pair(i,j));
  }
  int dy[] = { -1, 0, 1, 0 };
  int dx[] = { 0, -1, 0, 1 };
  while (!q.empty()) {
    int y, x, ny, nx;
    tie(y,x) = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
      ny = y+dy[i], nx = x+dx[i];
      if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
      if (d[ny][nx]!=INT_MAX) continue;
      d[ny][nx] = d[y][x]+1, q.push(make_pair(ny,nx));
    }
  }
  
  auto check = [&](int k) {
  	int z[4] = {INT_MAX, INT_MIN, INT_MAX, INT_MIN};
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
      if (d[i][j]>k)
        z[0] = min(z[0], i+j),
        z[1] = max(z[1], i+j),
        z[2] = min(z[2], i-j),
        z[3] = max(z[3], i-j);

    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
      if (abs(i+j-z[0]) <= k && abs(i+j-z[1]) <= k &&
          abs(i-j-z[2]) <= k && abs(i-j-z[3]) <= k)
        return 1;
    return 0;
  };
  int lo = 0, hi = INT_MIN;
  for (int i = 0; i < r; i++) hi = max(hi, *max_element(begin(d[i]), end(d[i])));
  while (lo < hi) {
    int m = lo + (hi-lo) / 2;
    check(m) ? hi = m : lo = m+1; 
  }
  return hi;
}

int main() {
  ios::sync_with_stdio(0);
  int t; cin >> t;
  for (int i = 1; i <= t; i++)
    cout << "Case #" << i << ": " << solve() << endl;
}