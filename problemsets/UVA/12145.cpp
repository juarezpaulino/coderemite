/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>


using namespace std;

const int MAXDIG = 60;     // Max non-decimal digits in a number.
const int MAXFRAC = 0;      // Max precision required for decimals.
const int BASE = 10000;     // Each v[i] is on BASE.
const int NBASE = 4;        // log10(BASE)
const int ROE = (MAXFRAC) ? 3 : 0;                  // Rounding of errors.
const int FRAC = (MAXFRAC*2+NBASE-1) / NBASE + ROE; // Max frac representation.
const int NDIG = (MAXDIG*2+NBASE-1) / NBASE + FRAC; // Max digit representation.
struct Num {
	int v[NDIG], n;
	Num(int x = 0) : n(FRAC+1) { memset(v, 0, sizeof(v)); v[n++] = x; fix(); }
	Num(char *S) : n(1) {
        int p, l, sign = 1; string T = S, F;
        memset(v, 0, sizeof(v));
        if (T.find("-")!=string::npos) { T = T.substr(1); sign = -1; }
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



typedef long long i64;

const int MAXD = 20;

struct poly {
    i64 P[MAXD];
    poly() { memset(P,0,sizeof(P)); }
    poly operator+(poly &B) {
        poly ret = B;
        for (int i = 0; i < MAXD; i++) ret.P[i] += P[i];
        return ret;
    }
    poly operator*(poly &B) {
        poly ret;
        for (int i = 0; i < MAXD; i++) for (int j = 0; j < MAXD; j++) ret.P[i+j] += P[i]*B.P[j];
        return ret;
    }
    poly operator-(poly &B) {
        poly ret = *this;
        for (int i = 0; i < MAXD; i++) ret.P[i] -= B.P[i];
        return ret;
    }
    void print() {
        for (int i = MAXD-1; i >= 0; i--) printf("%3lld ", P[i]);
        putchar('\n');
    }
};

string S;
int p;
int base;


poly term() {
    poly x;
    string s;
    while (p != S.size() && isdigit(S[p]))
        s += S[p++];
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        x.P[i] = s[i]-'0';
        if (x.P[i]+1 > base) base = x.P[i]+1;
    }
    return x;
}

poly factor() {
    poly x, y;
    x = term();
    while (p != S.size() && S[p]=='*') {
        char op = S[p++];
        y = term();
        if (op == '*') x = x * y;
    }
    return x;
}

poly expr() {
    poly x, y;
    x = factor();
    while (p != S.size()) {
        char op = S[p++];
        y = factor();
        if (op == '+') x = x + y;
        else if (op == '-') x = x - y;
    }
    return x;
}


int main() {

    char s[100];
    while (gets(s) && *s != '=') {
        bool sign = 1;
        S.clear();
        for (int i = 0; s[i]; i++)
            if (s[i]=='=') S += '-', sign = 0;
            else if (s[i]==' ') continue;
            else if (s[i]=='+') {
                if (sign) S += '+';
                else S += '-';
            }
            else S += s[i];
        base = 2;
        p = 0; poly P = expr();

        i64 Y = 0;
        for (int i = 0; i < MAXD; i++) if (P.P[i]) {
            Y = abs(P.P[i]);
            break;
        }
        if (Y == 0) { printf("%d+\n", base); continue; }

        vector<i64> C;
        {
        i64 f;
        for (f = 1; f*f < Y; f++) if (Y % f == 0) {
            if (f >= base) C.push_back(f);
            if (Y/f >= base) C.push_back(Y/f);
        }
        if (f*f == Y && f >= base) C.push_back(f);
        }

        vector<i64> ret;
        for (int i = 0; i < C.size(); i++) {
            Num r = 0;
            for (int j = MAXD-1; j >= 0; j--) r = r*C[i] + P.P[j];
            if (r == 0) ret.push_back(C[i]);
        }

        if (ret.size() == 0) { printf("*\n"); continue; }

        sort(ret.begin(), ret.end());
        printf("%lld", ret[0]);
        for (int i = 1; i < ret.size(); i++) printf(" %lld", ret[i]);
        putchar('\n');
    }


    return 0;
}
