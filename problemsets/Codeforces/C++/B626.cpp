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
  int n; cin >> n;
  string a; cin >> a;
  int r, g, b;
  r = g = b = 0;
  int u = 0;
  for (char c: a) (c=='R') ? r++,u|=1 :
                  (c=='G') ? g++,u|=2 :
                  (b++,u|=4);
  if (r>1 && b+g==1) cout << "BG";
  else if (g>1 && b+r==1) cout << "BR";
  else if (b>1 && r+g==1) cout << "GR";
  else if (__builtin_popcount(u)==1) cout << (g?"G":r?"R":"B");
  else if (r+g+b==2) cout << (!g?"G":!r?"R":"B");
  else cout << "BGR";
}