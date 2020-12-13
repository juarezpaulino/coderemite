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


const ld PI = 2*acos(0);
const int MOD = 1E9+7;


struct mi {
	typedef decay<decltype(MOD)>::type T; 
	T v; explicit operator T() const { return v; }
	mi() { v = 0; }
	mi(ll _v) { 
		v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
		if (v < 0) v += MOD;
	}
	friend bool operator==(const mi& a, const mi& b) { 
		return a.v == b.v; }
	friend bool operator!=(const mi& a, const mi& b) { 
		return !(a == b); }
	friend bool operator<(const mi& a, const mi& b) { 
		return a.v < b.v; }
	friend void re(mi& a) { ll x; re(x); a = mi(x); }
	friend str ts(mi a) { return ts(a.v); }
   
	mi& operator+=(const mi& m) { 
		if ((v += m.v) >= MOD) v -= MOD; 
		return *this; }
	mi& operator-=(const mi& m) { 
		if ((v -= m.v) < 0) v += MOD; 
		return *this; }
	mi& operator*=(const mi& m) { 
		v = (ll)v*m.v%MOD; return *this; }
	mi& operator/=(const mi& m) { return (*this) *= inv(m); }
	friend mi pow(mi a, ll p) {
		mi ans = 1; assert(p >= 0);
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	friend mi inv(const mi& a) { assert(a.v != 0); 
		return pow(a,MOD-2); }
		
	mi operator-() const { return mi(-v); }
	mi& operator++() { return *this += 1; }
	mi& operator--() { return *this -= 1; }
	friend mi operator+(mi a, const mi& b) { return a += b; }
	friend mi operator-(mi a, const mi& b) { return a -= b; }
	friend mi operator*(mi a, const mi& b) { return a *= b; }
	friend mi operator/(mi a, const mi& b) { return a /= b; }
};
typedef vector<mi> vmi;
typedef pair<mi,mi> pmi;
typedef vector<pmi> vpmi;
 
vector<vmi> scmb; // small combinations
void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	for (int i=1;i<SZ;i++) for (int j=0;j<i+1;j++) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}


void solve() {
  int n; re(n);
  vmi a(n); re(a);
  mi ret = 0, p = 1;
  for (int i=0;i<n;i++) {
    ret += a[i]*p - a[n-1-i]*p;
    p*=2;
  }
  ps(ret);
}


main() {
  //setbuf(stdout, NULL);
  setIO();

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}