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
  int n, x; cin >> n;
  string a;
  int y = 0;
  while (n--) {
    cin >> x >> a;
    if (y == 0 && a!="South") { cout << "NO"; return 0; }
    if (y == 20000 && a!="North") { cout << "NO"; return 0; }
    y += a=="North" ? -x : a=="South" ? x : 0;
    if (y < 0 || y > 20000) { cout << "NO"; return 0; }
  }
  cout << (y==0?"YES":"NO");
}