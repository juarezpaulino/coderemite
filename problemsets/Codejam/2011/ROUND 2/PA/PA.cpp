/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(M) (M).begin(), (M).end()
#define CLR(M, v) memset(M, v, sizeof(M))
#define SI(V) (int)(V.size())
#define PB push_back
#define MP make_pair
#define SORT(M) sort(ALL(M))
template<class T> inline void SORTG(vector<T> &M) { sort(ALL(M), greater<T>()); }
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int INF = 0x3F3F3F3F;
const i64 LINF = 0x3F3F3F3F3F3F3F3FLL;
const double DINF = 1E14;
const double EPS = 1E-14;
const double PI = 3.1415926535897932384626433832795;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template<class T> T SQR(T x) { return x*x; }

template <class T> T gcd(T a, T b) { return (b!=0) ? gcd(b, a % b) : a; }


////////////////////////////////////////////////////////////////////////////////

struct segment {
    int b, e;
    int w, speed;
    int p;
};

bool comp1(const segment &A, const segment &B) {
    if (A.w != B.w) return A.w < B.w;
    return A.p < B.p;
}

int main() {

//	freopen("A.in","r",stdin);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.ans","w",stdout);

    int TC;
    scanf("%d ", &TC);
    for (int tc = 1; tc <= TC; tc++) {

        vector<segment> seg;
        int X, S, R, N;
        double t;
        scanf("%d %d %d %lf %d", &X, &S, &R, &t, &N);
        {
            int l = 0, k;
            for (int i = 0; i < N; i++) {
                int b, e, w;
                scanf("%d %d %d", &b, &e, &w);
 //               printf("%d %d %d\n", b, e, w);
                if (b != l) { k = seg.size(); seg.push_back((segment){l,b,0,0,k}); }
                k = seg.size(); seg.push_back((segment){b,e,w,0,k});
                l = e;
            }
            if (l != X) { k = seg.size(); seg.push_back((segment){l,X,0,0,k}); }
        }
        sort(seg.begin(), seg.end(), comp1);
        double T = 0;
        for (int i = 0; i < seg.size(); i++) {
//            printf("%d %d %d\n", seg[i].b, seg[i].e, seg[i].w);
            if (cmp(t) > 0) {
                double tmax = (seg[i].e-seg[i].b)/(double)(R+seg[i].w);
                if (cmp(tmax,t) <= 0) {
                    T += tmax;
                    t -= tmax;
                }
                else {
                    double d = (double)(R+seg[i].w) * t;
                    T += t;
                    t = 0.;
                    T += ((seg[i].e-seg[i].b) - d) / (double)(S + seg[i].w);
                }
            }
            else {
                T += (seg[i].e-seg[i].b) / (double)(S + seg[i].w);
            }
        }

        printf("Case #%d: %.10lf\n", tc, T);
    }

	return 0;
}