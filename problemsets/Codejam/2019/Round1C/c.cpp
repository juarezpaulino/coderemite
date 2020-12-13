/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define FORE(a, x) for (auto& a : x)

#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define sz(v) ((int) (v).size())
#define beg(x) begin(x)
#define all(v) beg(v), end(v)
#define sqr(x) ((x)*(x))
#define ms(x,b) memset(x,b,sizeof(x))

const int MOD = 1000000007;
const ll INF = 1E18;
const double EPS = 1E-10;

template<class T> T ckmin(T &a, T b) { return a = min(a, b); }
template<class T> T ckmax(T &a, T b) { return a = max(a, b); }

namespace input {
    template<class T1, class T2> void re(pair<T1,T2>& p);
    template<class T> void re(vector<T>& a);
    template<class T> void re(T& x) { cin >> x; }
    void re(double& x) { string t; re(t); x = stod(t); }
    template<class A, class... As> void re(A& head, As&... tail) { 
        re(head); re(tail...); 
    }

    template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
    template<class T> void re(vector<T>& a) { FOR(i,0,sz(a)) re(a[i]); }
}

using namespace input;

namespace output {
    template<class T1, class T2> void pr(const pair<T1,T2>& x);
    template<class T> void pr(const vector<T>& x);
    template<class T> void pr(const set<T>& x);
    template<class T1, class T2> void pr(const map<T1,T2>& x);
    template<class T> void pr(const T& x) { cout << x; }
    template<class A, class... As> void pr(const A& head, const As&... tail) { 
        pr(head); pr(tail...); 
    }

    template<class T1, class T2> void pr(const pair<T1,T2>& x) { 
        pr("{",x.f,", ",x.s,"}"); 
    }
    template<class T> void prc(const T& x) {
        pr("{");
        bool fi = 1; FORE(a,x) pr(!fi?", ":"",a), fi = 0; 
        pr("}");
    }
    template<class T> void pr(const vector<T>& x) { prc(x); }
    template<class T> void pr(const set<T>& x) { prc(x); }
    template<class T1, class T2> void pr(const map<T1,T2>& x) { prc(x); }
    
    void ps() { pr("\n"); } 
    template<class A, class... As> void ps(const A& head, const As&... tail) { 
        pr(head," "); ps(tail...);
    }
}

using namespace output;


inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

typedef vector<string> vs;

int dy[2][2] = {{-1, 1}, {0, 0}};
int dx[2][2] = {{0, 0}, {-1, 1}};

void solve() {
  int r, c; re(r,c);

  vs m(r); re(m);
  int ret = 0;
  
  map<pair<int,vs>,bool> memo;
  
  auto place = [&](int y, int x, int t, char a, char b) {
    queue<pi> q;
    q.push(mp(y,x));
    m[y][x] = b;
    while (!q.empty()) {
      pi u = q.front(); q.pop();
      y = u.f, x = u.s;
      for (int k = 0; k < 2; k++) {
        int ny = y+dy[t][k], nx = x+dx[t][k];
        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if (m[ny][nx]=='#') return 0;
        if (m[ny][nx]!=a) continue;
        m[ny][nx] = b;
        q.push(mp(ny,nx));
      }
    }
    return 1;
  };

  function<bool(int,int,int,int)> run = [&](int f, int y, int x, int t) {
    if (memo.count(mp(t,m)) return memo[mp(t,m)];
    vs m2 = m; 
    bool ret = place(y,x,t,'.','b');

    FOR(i,0,r) FOR(j,0,c) if (ret && m[i][j]=='.')
      ret &= !run(1,i,j,0) && !run(1,i,j,1);

    m = m2;
    if (f) memo[mp(t,m))] = ret;
    return ret;
  };
  
  FOR(i,0,r) FOR(j,0,c) if (m[i][j]=='.') {
    if (run(0,i,j,0)) ret++;
    if (run(0,i,j,1)) ret++;
  }
  ps(ret);
}


int main() {
  //setbuf(stdout, NULL);
  //cin.tie(0);
  ios::sync_with_stdio(0);
  int t; re(t);
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}