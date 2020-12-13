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


int main() {

//	freopen("A.in","r",stdin);
	freopen("A-large-practice.in","r",stdin);freopen("A-small-attempt02.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
//	freopen("A-small-attempt3.in","r",stdin);freopen("A-small-attempt3.out","w",stdout);
//	freopen("A-large.in","r",stdin);freopen("A-large.ans","w",stdout);

    int NUM[110];
    for (int p = 0; p <= 100; p++) {
        bool ok = false;
        for (int N = 1; !ok && N <= 10000; N++) {
            for (int K = 0; !ok && K <= N; K++) {
                if ((K*100)%N==0 && (K*100)/N==p) {
                    NUM[p] = N;
                    ok = 1;
                }
            }
        }
    }

    int TC;
    scanf("%d ", &TC);
    for (int tc = 1; tc <= TC; tc++) {

        i64 N;
        int PD, PG;
        scanf("%lld %d %d", &N, &PD, &PG);

        printf("Case #%d: ", tc);

        if ((PG == 100 && PD != 100) || (PG==0 && PD != 0)) { puts("Broken"); continue; }

        if (N < NUM[PD]) puts("Broken");
        else puts("Possible");

    }

	return 0;
}
