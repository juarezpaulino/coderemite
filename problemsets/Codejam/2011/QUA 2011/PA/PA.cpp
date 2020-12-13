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
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.ans","w",stdout);

    int TC;
    scanf("%d ", &TC);
    for (int tc = 1; tc <= TC; tc++) {

        int N;
        vector<int> IN[2];

        // Read input.
        queue<PII> Q;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            char t;
            int b;
            scanf(" %c %d ", &t, &b);
            Q.push(PII(t,b));
            if (t == 'O') IN[0].push_back(b);
            else if (t == 'B') IN[1].push_back(b);
            else printf("%d", 1/0);
        }

        // Process input.
        int ret = 0;
        int p1 = 1, p2 = 1;
        int k1 = 0, k2 = 0;
        while (!Q.empty()) {
            int t = Q.front().first, p = Q.front().second;
            if (t == 'O') {
                if (p1 == p) Q.pop(), k1++;
                else if (p1 < p) p1++;
                else p1--;

                if (k2 < IN[1].size()) {
                    int r = IN[1][k2];
                    if (p2 == r) ;
                    else if (p2 < r) p2++;
                    else p2--;
                }
            }
            else {
                if (p2 == p) Q.pop(), k2++;
                else if (p2 < p) p2++;
                else p2--;

                if (k1 < IN[0].size()) {
                    int r = IN[0][k1];
                    if (p1 == r) ;
                    else if (p1 < r) p1++;
                    else p1--;
                }
            }
            ret++;
        }

        // Prints result.
        printf("Case #%d: %d\n", tc, ret);
    }

	return 0;
}
