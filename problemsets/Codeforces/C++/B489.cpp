/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {
  //setbuf(stdout, NULL);
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n; cin >> n;
  vi a(n); for (auto &u: a) cin >> u;
  int m; cin >> m;
  vi b(m); for (auto &u: b) cin >> u;
  sort(all(a)); sort(all(b));
  int y = 0, g = 0, ret = 0;
  while (y < n && g < m) {
    if (abs(a[y]-b[g]) <= 1) ret++, y++, g++;
    else if (a[y] > b[g]) g++;
    else y++;
  }
  cout << ret;
}