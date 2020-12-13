/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
// There is no general formula to find a primitive root. Typically, what you do is you pick a number and test. Once you find one primitive root, you find all the others.

// How you test

// To test that a
// is a primitive root of p you need to do the following. First, let s=ϕ(p) where ϕ() is the Euler's totient function. If p is prime, then s=p−1. Then you need to determine all the prime factors of s: p1,…,pk. Finally, calculate as/pimodp for all i=1…k, and if you find 1

// among residuals then it is NOT a primitive root, otherwise it is.

// So, basically you need to calculate and check k
// numbers where k is the number of different prime factors in ϕ(p)

// .

// Let us find the lowest primitive root of 761

// :

//     s=ϕ(761)=760=23×5×19

// the powers to test are: 760/2=380
// , 760/5=152 and 760/19=40
// (just 3 instead of testing all of them)
// test 2:

//     2380≡1mod761

//     oops

// test 3:

//     3380≡−1mod761

// OK
// 3152≡1mod761

//     oops

// test 5 (skip 4 because it is 22
// ):

//     5380≡1mod761

//     oops

// test 6:

//     6380≡−1mod761

// OK
// 6152≡67mod761
// OK
// 640≡−263mod761

//         hooray!

// So, the least primitive root of 761 is 6.

// How you pick

// Typically, you either pick at random, or starting from 2 and going up (when looking for the least primitive root, for example), or in any other sequence depending on your needs.

// Note that when you choose at random, the more prime factors are there in ϕ(p)

// , the less, in general, is the probability of finding one at random. Also, there will be more powers to test.

// For example, if you pick a random number to test for being a primitive root of 761
// , then the probability of finding one is roughly 12×45×1819 or 38%, and there are 3 powers to test. But if you are looking for primitive roots of, say, 2311

// then the probability of finding one at random is about 20% and there are 5 powers to test.

// How you find all the other primitive roots

// Once you have found one primitive root, you can easily find all the others. Indeed, if a
// is a primitive root mod p, and p is prime (for simplicity), then a can generate all other remainders 1…(p−1) as powers: a1≡a,a2,…,ap−1≡1. And ammodp is another primitive root if and only if m and p−1 are coprime (if gcd(m,p−1)=d then (am)(p−1)/d≡(ap−1)m/d≡1modp, so we need d=1). By the way, this is exactly why you have ϕ(p−1) primitive roots when p

// is prime.

// For example, 62=36
// or 615≡686 are not primitive roots of 761 because gcd(2,760)=2>1 and gcd(15,760)=5>1, but, for example, 63=216 is another primitive root of 761.



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

int MOD;


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

vmi modinv; // linear mod inverses
void genInv(int SZ) {
    modinv.resize(SZ+1); modinv[1] = 1;
    for(int i = 2; i <= SZ; i++) {
        modinv[i] = -(MOD/i)*modinv[MOD%i] + MOD;
    }
}

vector<vmi> scmb; // small combinations
void genComb(int SZ) {
	scmb.assign(SZ,vmi(SZ)); scmb[0][0] = 1;
	for (int i=1;i<SZ;i++) for (int j=0;j<i+1;j++) 
		scmb[i][j] = scmb[i-1][j]+(j?scmb[i-1][j-1]:0);
}

void squeeze(int &n, int p) { while (n%p==0) n/=p; }

vi prime_factors(int n) {
  vi ret;
  if (n%2==0) { ret.eb(2); squeeze(n,2); }
  if (n%3==0) { ret.eb(3); squeeze(n,3); }
  for (int p = 5; p*p <= n; p+=6) {
    if (n%p==0) { ret.eb(p); squeeze(n,p); }
    if (n%(p+2)==0) { ret.eb(p+2); squeeze(n,p+2); }
  }
  if (n!=1) { ret.eb(n); }
  return ret;
}


int least_primitive_root(int p) {
  MOD = p;
  vi primes = prime_factors(p-1);
  set<int> out;
  for (int r = 2; r < p; r++) if (!out.count(r)) {
    bool ok = 1;
    for (auto &u:primes) {
      dbg(u,pow(mi(r),(p-1)/u));
      if (pow(mi(r),(p-1)/u) == mi(1)) {
        ok = 0;
        break;
      }
    }
    if (ok) return r;
    out.insert(r*r);
  }
  return -1;
}

int euler_totient_function(int n) {
  int ret = n;
  for (int i = 2; i*i <= n; i++) 
    if (n%i==0) {
      ret -= ret / i;
      while (n%i==0) n/=i;
    }
  if (n > 1) ret -= ret / n;
  return ret;
}


int main() {
  //setbuf(stdout, NULL);
  //setIO();

  int p; re(p);
  int r = least_primitive_root(p);
  int k = euler_totient_function(p-1);
  ps(r,k);

  return 0;
}