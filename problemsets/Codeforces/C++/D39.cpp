/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int dist(int dx, int dy, int dz) {
  return dx*dx+dy*dy+dz*dz;
}

int main() {
  ios::sync_with_stdio(0);
  int x, y, z; cin >> x >> y >> z;
  int a, b, c; cin >> a >> b >> c;
  cout << (dist(x-a, y-b, z-c) <= 2 ? "YES" : "NO");
} 
