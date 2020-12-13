/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k; cin >> n >> k;
  auto a = vector<pair<int,int>>(n);
  for (auto &u: a) cin >> u.first >> u.second;
  double t = 0;
  auto dist = [](pair<int,int> u,pair<int,int> v) {
    int dx = u.first - v.first;
    int dy = u.second - v.second;
    return sqrt(dx*dx + dy*dy);
  };
  for (int i = 1; i < n; i++) t += dist(a[i],a[i-1]) / 50.;
  printf("%.8lf\n", t*k);
}
