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

typedef pair<int,int> pii;

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

void solve() {
  int r, c; cin >> r >> c;
  int mini, maxi;
  tie(mini,maxi) = minmax(r,c);
  if (mini == 1 || (mini==2 && maxi<5) || (mini==3 && maxi < 4)) { cout << "IMPOSSIBLE" << endl; return; }
  cout << "POSSIBLE" << endl;
  vector<pii> ret;
  if (r <= c) {
    for (int j = 0; j < c; j++) for (int i = 0; i < r; i++)
		  ret.eb(mp(i+1, (j+(i%2?r==2?3:2:0))%c+1));
  } else {
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++)
		  ret.eb(mp((i+(j%2?c==2?3:2:0))%r+1, j+1));
  }
  if (r == c && r%2==0) for (int i = ret.size()-1, j = 0; j < r; j+=2, i-=2) swap(ret[i], ret[i-1]);
  for (auto &u: ret) cout << u.fi << " " << u.se << endl;
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