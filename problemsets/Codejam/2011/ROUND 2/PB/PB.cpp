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

int R, C, D;
char W[1000][1000];


int main() {


//	freopen("B.in","r",stdin);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
	freopen("B-large.in","r",stdin);freopen("B-large.ans","w",stdout);

    int TC;
    scanf("%d ", &TC);
    for (int tc = 1; tc <= TC; tc++) {

        scanf("%d %d %d ", &R, &C, &D);
        for (int i = 0; i < R; i++) gets(W[i]);

        int maxi = min(R, C);
        int ret = -1;
        for (int s = maxi; s >= 3; s--) {
            for (int i = 0; i+s <= R; i++) for (int j = 0; j+s <= C; j++) {
                double cx = j+(s/2.), cy = i+(s/2.);
                double mx = 0, my = 0;
                for (int k = i; k < i+s; k++) for (int l = j; l < j+s; l++) {
                    if ((k==i && l==j) ||
                        (k==i && l==j+s-1) ||
                        (k==i+s-1 && l==j) ||
                        (k==i+s-1 && l==j+s-1)) continue;
                    mx += (l+.5 - cx) * (D + W[k][l]-'0');
                    my += (k+.5 - cy) * (D + W[k][l]-'0');
                }
                if (!cmp(mx) && !cmp(my)) { ret = s; goto OUT; }
            }
        }

OUT:
        // Prints result.
        printf("Case #%d: ", tc);
        if (ret == -1) puts("IMPOSSIBLE");
        else printf("%d\n", ret);
    }

	return 0;
}
