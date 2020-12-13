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

int s[101010][26] = {0};

void solve() {
  int n, q; cin >> n >> q;
  string a; cin >> a;
  memset(s, 0, sizeof(s));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++)
      s[i][j] = s[i-1][j] + (j==a[i-1]-'A'?1:0);
  }
  int ret = 0;
  while (q--) {
    int l, r; cin >> l >> r;
    int odd = 0;
    for (int j = 0; j < 26; j++) if ((s[r][j]-s[l-1][j])%2) odd++;
    if (odd < 2) ret++;
  }
  cout << ret << endl;
}

int main() {
  //setbuf(stdout, NULL);
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}