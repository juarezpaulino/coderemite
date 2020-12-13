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
typedef pair<char,char> PCC;

const int INF = 0x3F3F3F3F;
const i64 LINF = 0x3F3F3F3F3F3F3F3FLL;
const double DINF = 1E14;
const double EPS = 1E-8;
const double PI = 3.1415926535897932384626433832795;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template<class T> T SQR(T x) { return x*x; }

template <class T> T gcd(T a, T b) { return (b!=0) ? gcd(b, a % b) : a; }


////////////////////////////////////////////////////////////////////////////////

int C, D;
int P[300], V[300];

bool check(double m) {
    bool f = true;
    double L;
//    printf("TIME: %.4lf\n", m);
    for (int i = 0; i < C; i++) {
        for (int j = 0; j < V[i]; j++) {
            if (f) L = P[i] - m, f = 0;
            else {
                if (cmp(P[i],L+D) >= 0) {
                    double p = P[i]-m;
                    if (cmp(p,L+D) < 0) p = L + D;
                    L = p;
                }
                else {
                    double p = P[i]+m;
                    if (cmp(p,L+D) < 0) return false;
                    L = L+D;
                }
            }
//            printf("%.4lf\n", L);
//            getchar();
        }
    }
    return true;
}

int main() {

//	freopen("B.in","r",stdin);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
	freopen("B-large.in","r",stdin);freopen("B-large.ans","w",stdout);

    int TC;
    scanf("%d ", &TC);
    for (int tc = 1; tc <= TC; tc++) {

        scanf("%d %d", &C, &D);
        for (int i = 0; i < C; i++) scanf("%d %d", P+i, V+i);

        double lo = 0., hi = 1E16+10;
        for (int it = 0; it < 100; it++) {
            if (cmp(hi,lo)==0) break;
            double m = (hi+lo)/2.;
            if (check(m)) hi = m; else lo = m;
        }

        // Prints result.
        printf("Case #%d: %.10lf\n", tc, (hi+lo)/2.);
    }

	return 0;
}
