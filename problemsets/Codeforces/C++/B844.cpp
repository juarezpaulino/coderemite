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
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int main() {
  //setbuf(stdout, NULL);
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n, m; cin >> n >> m;
  int a[55][55];
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
  ll ret = n*m;
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < m; j++) if (a[i][j]) c++;
    ret += (c > 1) ? (1LL<<c)-c-1 : 0;
    ret += (m-c > 1) ? (1LL<<(m-c))-(m-c)-1 : 0;
  }
  for (int i = 0; i < m; i++) {
    int c = 0;
    for (int j = 0; j < n; j++) if (a[j][i]) c++;
    ret += (c > 1) ? (1LL<<c)-c-1 : 0;
    ret += (n-c > 1) ? (1LL<<(n-c))-(n-c)-1 : 0;
  }
  cout << ret;
}