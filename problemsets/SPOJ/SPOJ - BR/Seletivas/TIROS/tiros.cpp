/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a)) 
#define TLE while(1);
#define RTE printf("%d", 1/0);

using namespace std;
typedef vector<int> VI; typedef vector<double> VD; typedef vector<string> VS;
typedef vector<vector<int> > VVI; typedef vector<vector<string> > VVS;
typedef set<int> SI; typedef set<double> SD; typedef set<string> SS;
typedef pair<int,int> PII;
typedef signed long long i64; typedef unsigned long long u64;

#define EPS 1E-14
#define INF 0x3F3F3F3F
#define DINF 1E16
#define NULO -1

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int n, t;

struct point {
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(double t) { return point(x * t, y * t); }
    point operator /(double t) { return point(x / t, y / t); }
    double operator *(point q) { return x * q.x + y * q.y; }
    double operator %(point q) { return x * q.y - y * q.x; }
    int cmp(point q) const {
        if (int t = ::cmp(x, q.x)) return t;
        return ::cmp(y, q.y);
    }
    bool operator ==(point q) const { return cmp(q) == 0; }
    bool operator !=(point q) const { return cmp(q) != 0; }
    bool operator < (point q) const { return cmp(q) < 0; }
    static point pivot;
};
point point::pivot;


/*******************************************************************************
 * Retorna <0, 0, >0 para cw, colinear, ccw
 */
inline int ccw(point p, point q, point r) {
    return cmp((p - r) % (q - r));
}

/*******************************************************************************
 * Compara??o radial.
 */
bool radial_lt(point p, point q) {
    point P = p - point::pivot, Q = q - point::pivot; double R = P % Q;
    return (cmp(R)) ? R > 0 : cmp(P * P, Q * Q) < 0;
}

bool cart_lt(point a, point b) {
    return cmp(a.y,b.y) ? (a.y<b.y) : (a.x<b.x);    
}


/*******************************************************************************
 * Conta a quantidade m?xima de pontos que passam em uma ?nica reta.
 * Dep: ccw, radial_lt. O(n^2logn)
 */
int max_colin(vector<point>& T) {
    int i, j, s, n = SI(T); if (n==1) return 1;
    int maxi = 2; sort(ALL(T), cart_lt);
    FOR(i, n) {
        point::pivot = T[i];
        sort(T.begin()+i, T.end(), radial_lt);
        for (j = i+1, s = 2; j < n-1; j++)
            ccw(T[i], T[j], T[j+1])==0 ? (s++, maxi>?=s) : s = 2;
    }
    return maxi;
}

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch=='-')?(ch=getchar(),-1):1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}


int main() {
    
    int i, j;
    int s;
    
    for (t = get_int(); t--; ) {
        n = get_int();
        vector<point> p(n);
        for (i = 0; i < n; i++) p[i].x = get_int(), p[i].y = get_int();
        if (n<2) { printf("%d\n", n); continue; }
        printf("%d\n", max_colin(p));
    }
    
    return 0;
}

