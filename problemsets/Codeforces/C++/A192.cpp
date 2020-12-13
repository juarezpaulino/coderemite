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
  vi T; T.eb(0);
  unordered_set<int> P;
  for (int i = 1; T[i-1] < (1<<30); i++) {
    T.eb(T[i-1]+i), P.insert(T[i]);
  }
  int n; cin >> n;
  for (int i = 1; i < sz(T) && T[i] < n; i++) if (P.count(n-T[i])) {
    cout << "YES"; return 0;
  }
  cout << "NO";
}