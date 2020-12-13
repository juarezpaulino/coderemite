/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define FORE(a, x) for (auto& a : x)

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
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

template<class T> T invMod(T a, T b) {
    a %= b; if (a == 0) return b == 1 ? 0 : -1;
    T x = invMod(b,a); 
    return x == -1 ? -1 : ((1-(ll)b*x)/a+b)%b;
}

template<class T> struct modular {
    T val; 
    explicit operator T() const { return val; }
    modular() { val = 0; }
    template<class U> modular(const U& v) {
        val = (-MOD <= v && v <= MOD) ? v : v % MOD;
        if (val < 0) val += MOD;
    }
    friend ostream& operator<<(ostream& os, const modular& a) { return os << a.val; }
    friend bool operator==(const modular& a, const modular& b) { return a.val == b.val; }
    friend bool operator!=(const modular& a, const modular& b) { return !(a == b); }

    modular operator-() const { return modular(-val); }
    modular& operator+=(const modular& m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
    modular& operator-=(const modular& m) { if ((val -= m.val) < 0) val += MOD; return *this; }
    modular& operator*=(const modular& m) { val = (ll)val*m.val%MOD; return *this; }
    friend modular exp(modular a, ll p) {
        modular ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend modular inv(const modular& a) { return invMod(a.val,MOD); } 
    // inv is equivalent to return exp(b,b.mod-2) if prime
    modular& operator/=(const modular& m) { return (*this) *= inv(m); }
    
    friend modular operator+(modular a, const modular& b) { return a += b; }
    friend modular operator-(modular a, const modular& b) { return a -= b; }
    friend modular operator*(modular a, const modular& b) { return a *= b; }
    
    friend modular operator/(modular a, const modular& b) { return a /= b; }
};

typedef modular<ll> mi;
typedef pair<mi,mi> pmi;
typedef vector<mi> vmi;
typedef vector<pmi> vpmi;

int main() {
  //setbuf(stdout, NULL);
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n; re(n);
  ps(exp(mi(27),n)-exp(mi(7),n));
}
