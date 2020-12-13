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

int G[1010101];
vi S[10];

int g(int x) {
  int &ret = G[x];
  if (ret) return ret;
  if (x < 10) return ret = x;
  int f = 1;
  while (x) f *= max(1,x%10), x/=10;
  return ret = g(f);
}

int main() {
  //setbuf(stdout, NULL);
  cin.tie(0);
  ios::sync_with_stdio(0);
  for (int i = 1; i <= 1000000; i++) S[g(i)].eb(i);
  int q; cin >> q;
  while (q--) {
    int l, r, k; cin >> l >> r >> k;
    cout << upper_bound(all(S[k]),r) - upper_bound(all(S[k]), l-1) << endl;
  }
}