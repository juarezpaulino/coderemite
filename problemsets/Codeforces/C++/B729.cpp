/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define sz(v) ((int) (v).size())
#define all(v) (v).begin(), (v).end()
#define ms(x,b) memset(x,b,sizeof(x))
#define sqr(x) ((x)*(x))

typedef string str;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;

// UTILS
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; } 
template<class T> int pct(T x) { return __builtin_popcount(x); }
template<class T> int bits(T x) { return T(sizeof(T))*8-__builtin_clz(x); }
template<class T> T divup(T a, T b) { return a/b+!(a<0||a%b == T(0)); }
int fstTrue(function<bool(int)> f, int lo, int hi) {
  hi++; assert(lo <= hi);
  while (lo < hi) {  
    int mid = lo + (hi-lo)/2; 
    f(mid) ? hi = mid : lo = mid+1; // find first true
  }
  return lo;
}
int fstFalse(function<bool(int)> f, int lo, int hi) {
  hi++; assert(lo <= hi);
  while (lo < hi) {  
    int mid = lo + (hi-lo)/2; 
    f(mid) ? lo = mid+1 : hi = mid; // find first false
  }
  return lo;
}

// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);
 
template<class T> void re(T& x) { cin >> x; }
void re(double& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
 
template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.fi,p.se); }
template<class A> void re(vector<A>& x) { for (auto &u:x) re(u); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { for (auto &u:x) re(u); }

// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(bool b) { return b ? "true" : "false"; }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
template<class A> str ts(complex<A> c) { stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) { 
  str res = "{";
  for (int i=0;i<sz(v);i++) res += char('0'+v[i]);
  res += "}";
  return res;
}
template<size_t SZ> str ts(bitset<SZ> b) {
  str res = ""; for (int i=0;i<SZ;i++) res += char('0'+b[i]);
  return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) {
  bool f = 1; str r = "{";
  for (const auto& x: v) { if (!f) r += ", "; f = 0; r += ts(x); }
  r += "}"; return r; }
template<class A, class B> str ts(pair<A,B> p) {
  return "("+ts(p.fi)+", "+ts(p.se)+")"; }
 
// OUTPUT
void pr(double x) { cout << fixed << setprecision(10) << x; }
void pr(ld x) { cout << fixed << setprecision(10) << x; }
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
  pr(h); pr(t...); }
void ps() { pr("\n"); }
template<class H, class... T> void ps(const H& h, const T&... t) { 
  pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
template<class A> void pv(A v) { int n = sz(v); for (int j=0;j<n;j++) pr(v[j]," \n"[j==n-1]); }
 
// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
  cerr << ts(h); if (sizeof...(t)) cerr << ", ";
  DBG(t...); }
#ifdef LOCAL
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
 
// FILE I/O
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(string s = "") {
  unsyncIO();
  // cin.exceptions(cin.failbit); 
  // throws exception when do smth illegal
  // ex. try to read letter into int
  if (sz(s)) { setIn(s+".in"), setOut(s+".out"); }
}

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ld PI = 2*acos(0);
const int INF = 1E9+7;



main() {
  //setbuf(stdout, NULL);
  setIO();

  int n, m; re(n,m);
  vvi a(n, vi(m)); re(a);
  int ret = 0;
  for (int i=0;i<n;i++) {
    bool ok = 0;
    for (int j=0;j<m;j++) {
      ok |= a[i][j];
      ret += !a[i][j] & ok;
    }
    ok = 0;
    for (int j=m-1;j>=0;j--) {
      ok |= a[i][j];
      ret += !a[i][j] & ok;
    }
  }
  for (int j=0;j<m;j++) {
    bool ok = 0;
    for (int i=0;i<n;i++) {
      ok |= a[i][j];
      ret += !a[i][j] & ok;
    }
    ok = 0;
    for (int i=n-1;i>=0;i--) {
      ok |= a[i][j];
      ret += !a[i][j] & ok;
    }
  }
  ps(ret);
}