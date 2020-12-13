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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpi;
typedef long long ll;

ll nCm(int n, int m) {
    int k = (m > (n-m)) ? m : (n-m);
    ll c = 1, d = 1, i, j;
    for (j = 1, i = k+1; i <= n; i++, j++) {
        c *= i; d *= j;
        if (c%d==0 && (d!=1)) { c /= d; d = 1;}
    }
    return c;
}

int dx[] = {1,-1};

void solve() {
  int n; cin >> n;
  n--;
  int c = n>>1;
  vpi ret;
  int l=499;
  int y=1,x=1,k=0;
  ret.eb(mp(y,x));
  while (c!=1 && n>l) {
    y++;x+=k;
    ret.eb(mp(y,x));
    l--;
    if (c&1) {
      n-=1<<(y-1);
      for (int i = 0; i < y-1; i++) {
        x+=dx[k];
        ret.eb(mp(y,x));
        l--;
      }
      k^=1;
    }
    else n--;
    c>>=1;
  }
  while (n>l) {
    ll c=2+k;
    l-=2+k;
    int u = 1;
    while (n>l) {
      c+=nCm(y,u)+nCm(y+1,u);
      if (n-c < 0) break;
      u++; l-=2;
    }
    n-=c;
    y++; x+=k;
    ret.eb(mp(y,x));
    for (int i = 0; i < u-1; i++) x+=dx[k],ret.eb(mp(y,x));
    k^=1;
    y++;
    ret.eb(mp(y,x));
    for (int i = 0; i < u-1; i++) x+=dx[k],ret.eb(mp(y,x));
    if (!k) x+=dx[k],ret.eb(mp(y,x));
    k^=1;
  }
  while (n) {
    y++; x+=k;
    ret.eb(mp(y,x));
    n--;
  }
  cout << endl;
  for (auto &u:ret) {
    cout << u.first << " " << u.second << endl;
  }
}

int main() {
  //	setbuf(stdout, NULL);
 	cin.tie(0);
  ios::sync_with_stdio(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}