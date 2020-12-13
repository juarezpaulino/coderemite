/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b; cin >> a >> b;
  int n; cin >> n;
  int x, y, v;
  double best = 1E12;
  auto dist = [](int x1, int x2, int y1, int y2) {
    int dx = x1-x2,
        dy = y1-y2;
    return sqrt(dx*dx + dy*dy);
  };
  while (n--) {
    cin >> x >> y >> v;
    double t = dist(x,a,b,y)/v;
    if (t < best) best = t; 
  }
  printf("%.8lf\n", best);
}
