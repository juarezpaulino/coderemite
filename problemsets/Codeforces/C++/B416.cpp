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
typedef vector<pii> vpii;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {
  //setbuf(stdout, NULL);
  cin.tie(0);
  ios::sync_with_stdio(0);
  int m, n; cin >> m >> n;
  vector<vi> a(m, vi(n));
  for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 1; i < m; i++) a[i][0] += a[i-1][0];
  for (int j = 1; j < n; j++) a[0][j] += a[0][j-1];
  for (int i = 1; i < m; i++) for (int j = 1; j < n; j++) a[i][j] += max(a[i-1][j], a[i][j-1]);
  for (int i = 0; i < m; i++) cout << a[i][n-1] << " ";
}