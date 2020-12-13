/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: fence6
 LANG: C++
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>


using namespace std;

#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(M) (M).begin(), (M).end()
#define CLR(M, v) memset(M, v, sizeof(M))
#define SI(V) (int)(V.size())
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SORT(M) sort(ALL(M))
template<class T> inline void SORTG(vector<T> &M) { sort(ALL(M), greater<T>()); }
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;

const int INF = 0x3F3F3F3F;
const i64 LINF = 0x3F3F3F3F3F3F3F3FLL;
const double DINF = 1E16;
const double EPS = 1E-10;
const double PI = 3.1415926535897932384626433832795;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template<class T> T SQR(T x) { return x*x; }

template <class T> T gcd(T a, T b) { return (b!=0) ? gcd(b, a % b) : a; }

inline string ITOA(int a) { char c[500]; sprintf(c,"%d",(a)); return string(c); }

inline int POPC(int a) { return __builtin_popcount(a); }

/*******************************************************************************
 * HASH
 ******************************************************************************/
struct STATE {
    int X[20], Y[20], deg;
    bool operator==(const STATE& S) const {
        for (int i = 0; i < 20; i++)
            if (X[i]!=S.X[i] || Y[i]!=S.Y[i]) return false;
        return true;
    }
};
#ifdef VCC
#include<hash_map>
#include<hash_set>
using namespace stdext;
#else
#include<ext/hash_map>
#include<ext/hash_set>
using namespace __gnu_cxx;
namespace __gnu_cxx {
	template<> struct hash<string> {
		size_t operator()(const string& X) const {
			return hash<const char*>() (X.c_str());
		}
	};
    template<> struct hash<VI> {
		size_t operator()(const VI& S) const {
            size_t p = 0;
            FOR(i,0,SI(S)) p = (p*10) + S[i];
            return p;
		}
	};
	template<> struct hash<STATE> {
		size_t operator()(const STATE& S) const {
            size_t p = 0;
            for (int i = 0; i < 20; i++) { p |= 1<<(S.Y[i]*6 + S.X[i]); }
            return p;
		}
	};
}
#endif

////////////////////////////////////////////////////////////////////////////////

const int MAXV = 200;

int N;
int EDGE[MAXV][2][8], NEDGE[MAXV][2], COST[MAXV], L[MAXV], ID[MAXV][MAXV];

int M, mini;
int ADJ[MAXV][MAXV], CUSTO[MAXV][MAXV], NADJ[MAXV];
int MARC[MAXV], DIST[MAXV], PAR[MAXV], PROF[MAXV];


void dijkstra(int ini) {
    int i, j, k, d;
    priority_queue<pair<int, int> > HEAP;
    FOR(i,0,M) DIST[i] = INF, MARC[i] = 0, PAR[i] = -1;
    HEAP.push(make_pair(DIST[ini] = 0, ini)); PROF[ini] = 0;
    while (!HEAP.empty()) {
        i = HEAP.top().second; HEAP.pop();
        if (MARC[i]) continue; MARC[i] = 1;
        for (k = 0; k < NADJ[i]; k++) {
            j = ADJ[i][k]; d = DIST[i] + CUSTO[i][k];
            if (MARC[j] && PAR[i]!=j)
                mini = min(mini, d+DIST[j]);
            if (d < DIST[j]) {
                PAR[j] = i;
                HEAP.push(make_pair( -(DIST[j] = d), j));
                PROF[j] = PROF[i]+1;
            }
        }
    }
}


int main() {

    freopen("fence6.in","r",stdin);freopen("fence6.out","w",stdout);

    CLR(ID,-1); M = 0;
    scanf("%d", &N);
    FOR(i,0,N) {
        int S, C, N1, N2; scanf("%d %d %d %d", &S, &C, &N1, &N2);
        L[i] = S-1;
        COST[S-1] = C; NEDGE[S-1][0] = N1; NEDGE[S-1][1] = N2;
        int y = M;
        FOR(j,0,N1) {
            int x; scanf("%d", &x); EDGE[S-1][0][j] = x-1;
            if (ID[x-1][S-1]!=-1) y = ID[x-1][S-1];
        }
        if (y == M) M++;
        FOR(j,0,N1) ID[S-1][EDGE[S-1][0][j]] = y;
        y = M;
        FOR(j,0,N2) {
            int x; scanf("%d", &x); EDGE[S-1][1][j] = x-1;
            if (ID[x-1][S-1]!=-1) y = ID[x-1][S-1];
        }
        if (y == M) M++;
        FOR(j,0,N2) ID[S-1][EDGE[S-1][1][j]] = y;
    }

    // Build adjacency list.
    CLR(NADJ,0);
    FOR(i,0,N) {
        int x = L[i], u = ID[x][EDGE[x][0][0]], v = ID[x][EDGE[x][1][0]];
        ADJ[u][NADJ[u]] = v; CUSTO[u][NADJ[u]++] = COST[x];
        ADJ[v][NADJ[v]] = u; CUSTO[v][NADJ[v]++] = COST[x];
    }

/*    FOR(i,0,M) {
        printf("%d:", i);
        FOR(j,0,NADJ[i]) printf("  %d/%d  ", ADJ[i][j], CUSTO[i][j]);
        putchar('\n');
    }
*/

    // Get perimeter.
    mini = INF;
    FOR(i,0,M) dijkstra(i);

    printf("%d\n", mini);

    return 0;
}
