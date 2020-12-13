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

const double EPS = 1E-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MAXDIG = 220;     // Max non-decimal digits in a number.
const int MAXFRAC = 0;      // Max precision required for decimals.
const int BASE = 10000;     // Each v[i] is on BASE.
const int NBASE = 4;        // log10(BASE)
const int ROE = (MAXFRAC) ? 3 : 0;                  // Rounding of errors.
const int FRAC = (MAXFRAC*2+NBASE-1) / NBASE + ROE; // Max frac representation.
const int NDIG = (MAXDIG*2+NBASE-1) / NBASE + FRAC; // Max digit representation.
struct Num {
	int v[NDIG], n;
	Num(int x = 0) : n(FRAC+1) { memset(v, 0, sizeof(v)); v[n++] = x; fix(); }
	Num(string &T) : n(1) {
        int p, l, sign = 1;
        string F;
        memset(v, 0, sizeof(v));
        if (T.find("-")!=-1) { T = T.substr(1); sign = -1; }
        if (FRAC) {
            if ((p = T.find("."))==-1) T += "." + string(FRAC*NBASE,'0');
            else T += string(FRAC*NBASE-(T.size()-p-1),'0');
        }
        if ((p = T.find(".")) != -1) {
            F = T.substr(p+1); T = T.substr(0,p);
            for (p = F.size()-NBASE; p >= 0; p-=NBASE) {
                sscanf(F.substr(p,NBASE).c_str(), "%d", &v[n]);
                v[n++] *= sign;
            }
        }
        for (p = T.size()-NBASE; p > -NBASE; p-=NBASE) {
            (p < 0) ? (l = NBASE+p, p = 0) : (l = NBASE);
            sscanf(T.substr(p,l).c_str(), "%d", &v[n]);
            v[n++] *= sign;
        }
        fix();
    }
	inline Num& fix(int m = 0) {
        n = max(m, n); int sign = 0;
        for (int i = 1, e = 0; i <= n || e && (n = i); i++) {
            v[i] += e; e = v[i] / BASE; v[i] %= BASE;
            if (v[i]) sign = (v[i] > 0) ? 1 : -1;
        }
        for (int i = 1; i <= n; i++) if (v[i] * sign < 0)
            v[i] += sign * BASE, v[i+1] -= sign;
        while (n > FRAC && !v[n]) n--;
        return *this;
	}
	int cmp(const Num &x = 0) const {
        int i = max(n, x.n), t;
        while (1) if ((t = v[i]-x.v[i]) || i-- == 0) return (FRAC && i<=1) ? 0 : t;
    }
    bool operator <(const Num& x) const { return cmp(x) < 0; }
    bool operator <=(const Num& x) const { return cmp(x) <= 0; }
    bool operator >(const Num& x) const { return cmp(x) > 0; }
    bool operator >=(const Num& x) const { return cmp(x) >= 0; }
    bool operator ==(const Num& x) const { return cmp(x) == 0; }
    bool operator !=(const Num& x) const { return cmp(x) != 0; }
	Num& operator+=(const Num &x) {
        for (int i = 1; i <= x.n; i++) v[i] += x.v[i];
        return fix(x.n);
	}
	Num operator+(const Num &x) { return Num(*this)+=x; }
	Num& operator -=(const Num& x) {
        for (int i = 1; i <= x.n; i++) v[i] -= x.v[i];
        return fix(x.n);
    }
    Num operator-(const Num& x) { return Num(*this) -= x; }
    Num operator -() { Num r; return r -= *this; }
	void ams(const Num& x, int m, int b) { // *this += (x * m) << b;
        for (int i = 1, e = 0; (i <= x.n || e) && (n = i + b); i++)
            v[i+b] += x.v[i] * m + e, e = v[i+b] / BASE, v[i+b] %= BASE;
    }
    Num operator *(const Num& x) {
        Num r; int i;
        for (i = 1; i <= n; i++) r.ams(x, v[i], i-1);
        if (FRAC) {
            for (i = 1; i <= r.n; i++) r.v[i] = (i <= r.n-FRAC) ? r.v[i+FRAC] : 0;
            r.n-=FRAC; if (r.n < FRAC) r.n = FRAC;
        }
        return r;
    }
    Num& operator *=(const Num& x) { return *this = *this * x; }
    Num div(const Num& x) {
        if (x == 0) return 0;
        Num q; q.n = max(n - x.n + 1, 0);
        int d = x.v[x.n] * BASE + x.v[x.n-1];
        for (int i = q.n; i > 0; i--) {
            int j = x.n + i - 1;
            q.v[i] = int((v[j] * double(BASE) + v[j-1]) / d);
            ams(x, -q.v[i], i-1);
            if (i == 1 || j == 1) break;
            v[j-1] += BASE * v[j]; v[j] = 0;
        }
        fix(x.n); return q.fix();
    }
    friend Num div2(const Num &A) {
        Num ret = A;
        int sign = ret.v[ret.n]<0 ? -1 : 1;
		for (int i = ret.n, p = 0; i > 0; i--)
			ret.v[i] += p, p = ((ret.v[i]%2) ? sign*BASE : 0), ret.v[i]/=2;
		while (ret.n > FRAC && !ret.v[ret.n]) ret.n--;
		return ret;
	}
    Num& operator /=(const Num& x) { return *this = div(x); }
    Num& operator %=(const Num& x) { div(x); return *this; }
    Num operator /(const Num& x) { return Num(*this).div(x); }
    Num operator %(const Num& x) { return Num(*this) %= x; }
    Num pow(int k) {
        if (!k) return 1;
        if (k==1) return *this;
        Num x = (*this**this).pow(k>>1);
        return (k&1) ? *this*x : x;
    }
    Num root(int x) {
        if (cmp() == 0 || cmp() < 0 && x % 2 == 0) return 0;
        if (*this == 1 || x == 1) return *this;
        if (cmp() < 0) return -(-*this).root(x);
        Num lo = 1, hi = *this, mi;
        for (int i = 0; lo < hi && i < 1000; i++) {
            mi = div2(lo + hi);
            int c = cmp(mi.pow(x));
            if (c == 0) break;
            (c < 0) ? (hi = mi) : (lo = mi, mi.v[0]+1);
        }
        return mi;
    }
    ///////////////////////////////////////////////////////////////////////////
    // Newton root - x' = x - f(x) / f'(x) - Use for small values of p.
    Num newton_root(int p) {
        Num mi(*this);
        int m = mi.n/p;
        int k = 0; for (int i = m+1; i <= n; i++) mi.v[++k] = v[i];
        mi.n = k; mi.fix();
        for (int i = 0; ; i++) {
            Num x = (mi*(p-1) + (*this / mi.pow(p-1))) / p;
            if (i == 100) { mi = div2(mi+x); break; }
            if (x.cmp(mi) == 0) break;
            mi = x;
        }
        return mi;
    }
    ///////////////////////////////////////////////////////////////////////////
    // Newton - x' = x - f(x) / f'(x)
    Num sqrt() {
        Num mi(*this);
        int m = mi.n/2;
        int k = 0; for (int i = m+1; i <= n; i++) mi.v[++k] = v[i];
        mi.n = k; mi.fix();
        for (int i = 0; ; i++) {
            Num x = div2(mi + (*this / mi));
            if (i == 100) { mi = div2(mi+x); break; }
            if (x.cmp(mi) == 0) break;
            mi = x;
        }
        return mi;
    }
    friend Num abs(const Num &x) {
        Num ret = x;
        for(int i = 1; i <= x.n; i++) ret.v[i] = abs(x.v[i]);
        return ret;
    }
    operator string() const {
        ostringstream s;
        if (v[n]<0) s << '-';
        if (FRAC && n <= FRAC) { s << "0."; s.width(NBASE); s.fill('0'); }
        s << abs(v[n]);
        for (int i = n - 1; i > 0; i--) {
            if (i==FRAC) s << '.';
            s.width(NBASE); s.fill('0'); s << abs(v[i]);
        }
        string ss = s.str();
        if (FRAC) ss = ss.substr(0,ss.find(".")+1+MAXFRAC);
        return ss;
    }
};

template <class T> T gcd(T a, T b) { return b>0 ? gcd(b, a % b) : a; }

void solve() {
  string n;
  int l;
  cin >> n >> l;
  map<string,char> decoder;
  vector<string> encoded(l);
  for (auto &u: encoded) cin >> u;
  vector<string> plain;
  string a = encoded[0], b;
  bool sw = 0;
  for (int i = 1; i < l; i++, sw^=1) if (encoded[i] != a) { b = encoded[i]; break; }
  Num A(a), B(b);
  Num y = gcd(A,B), x = A/y;
  if (sw) x = y;
  plain.eb(string(x));
  for (int i = 0; i < l; i++) {
    y = Num(encoded[i])/x;
    plain.eb(string(y));
    x = y;
  }
  vector<string> cr = plain;
  sort(all(cr), [](string &a, string &b){ return a.size() != b.size() ? a.size() < b.size() : a < b;});
  cr.resize(unique(all(cr))-begin(cr));
  char c = 'A';
  for (auto &u: cr) decoder[u] = (char)(c++);
  for (auto &u: plain) cout << decoder[u];
  cout << endl;
}

int main() {
  //setbuf(stdout, NULL);
 	cin.tie(0);
  ios::sync_with_stdio(0);

  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}