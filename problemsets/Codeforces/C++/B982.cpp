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
  int n, m, x; cin >> n;
  priority_queue<pii, vpii, greater<pii>> itr;
  priority_queue<pii> ext;
  m = n<<1;
  for (int i = 0; i < n; i++) cin >> x, itr.push(mp(x,i+1));
  string a; cin >> a;
  for (int i = 0; i < m; i++) {
    int x, y;
    if (a[i]=='0') tie(y,x) = itr.top(), itr.pop(), ext.push(mp(y,x));
    else tie(y,x) = ext.top(), ext.pop();
    cout << x << " ";
  }
}