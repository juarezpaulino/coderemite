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

int N;
char MAT[110][110];
double wp[110];
double owp[110];
double oowp[110];

double WP(int u) {
    if (wp[u] > -.5) return wp[u];
    int c = 0, w = 0;;
    for (int i = 0; i < N; i++) if (u != i && MAT[u][i] != '.') {
        c++;
        if (MAT[u][i]=='1') w++;
    }
    return wp[u] = w / (double) c;
}

double OWP(int u) {
    if (owp[u] > -.5) return owp[u];
    int c = 0;
    vector<int> v;
    for (int i = 0; i < N; i++) if (u != i && MAT[u][i] != '.') {
        c++;
        v.push_back(i);
    }
    double ret = 0;
    for (int i = 0; i < (int)v.size(); i++) {
        int c2 = 0, w2 = 0;
        for (int j = 0; j < N; j++) if (u != j && v[i] != j && MAT[v[i]][j]!='.') {
            c2++;
            if (MAT[v[i]][j]=='1') w2++;
        }
        ret += w2 / (double) c2;
    }
    return owp[u] = ret / (double) c;
}

double OOWP(int u) {
    if (oowp[u] > -.5) return oowp[u];
    int c = 0;
    double ret = 0;
    for (int i = 0; i < N; i++) if (u != i && MAT[u][i] != '.') {
        c++;
        ret += OWP(i);
    }
    return oowp[u] = ret / (double) c;
}

double rank(int u) {
    return .25 * WP(u) + .5 * OWP(u) + .25 * OOWP(u);
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

        scanf("%d ", &N);
        for (int i = 0; i < N; i++) scanf("%s", MAT[i]);

        for (int i = 0; i < N; i++) wp[i] = owp[i] = oowp[i] = -1;

        printf("Case #%d:\n", tc);
        for (int i = 0; i < N; i++) {
            printf("%.10lf\n", rank(i));
        }
    }

	return 0;
}
