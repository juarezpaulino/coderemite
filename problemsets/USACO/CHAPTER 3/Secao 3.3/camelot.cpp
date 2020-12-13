/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: camelot
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

const int INF = 100000;
const i64 LINF = 0x3F3F3F3F3F3F3F3FLL;
const double DINF = 1E16;
const double EPS = 1E-14;
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

const int MAXD = 30;

int R, C;

int dy[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dx[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
inline bool in_bound(int y, int x) { return y >= 0 && x >= 0 && y < R && x < C; }

int COST[MAXD][MAXD], KCOST[MAXD][MAXD];
int KING[MAXD][MAXD];
char DISC[2][MAXD][MAXD];
int DIST[2][MAXD][MAXD];
int Y[MAXD*MAXD], X[MAXD*MAXD];
int N;

struct Triple {
    int y, x, k, d;
    bool operator<(const Triple &B) const {
        return d > B.d;
    }
};

void dijkstra(int sy, int sx) {
    priority_queue<Triple> q;
    FOR(i,0,2) FOR(j,0,MAXD) FOR(l,0,MAXD) DIST[i][j][l] = INF, DISC[i][j][l] = 0;
    q.push((Triple){sy,sx,0,(DIST[0][sy][sx]=0)});
    q.push((Triple){sy,sx,1,(DIST[1][sy][sx]=KING[sy][sx])});
    while (!q.empty()) {
        int y = q.top().y, x = q.top().x, k = q.top().k; q.pop();
        if (DISC[k][y][x]) continue;
        DISC[k][y][x] = 1;
        FOR(l,0,8) {
            int ny = y+dy[l], nx = x+dx[l];
            int d = DIST[k][y][x]+1;
            if (!in_bound(ny, nx)) continue;
            if (DIST[k][ny][nx] > d)
                q.push((Triple){ny,nx,k,(DIST[k][ny][nx]=d)});
            if (k==0 && DIST[1][ny][nx] > d+KING[ny][nx])
                q.push((Triple){ny,nx,1,(DIST[1][ny][nx]=d+KING[ny][nx])});
        }
    }
}

int main() {

    freopen("camelot.in","r",stdin);freopen("camelot.out","w",stdout);

    scanf("%d%d", &R, &C);
    char c[10]; int r;
    for (N = 0; scanf("%s %d", c, &r)!=EOF; N++) {
        Y[N] = r-1; X[N] = c[0]-'A';
    }
    FOR(i,0,R) FOR(j,0,C) {
        int ay = abs(Y[0]-i), ax = abs(X[0]-j);
        KING[i][j] = min(ay,ax) + abs(ay-ax);
    }

    FOR(i,0,MAXD) FOR(j,0,MAXD) COST[i][j] = 0, KCOST[i][j] = KING[i][j];

    FOR(i,1,N) {
        dijkstra(Y[i], X[i]);
        FOR(i,0,R) FOR(j,0,C) {
            COST[i][j] += DIST[0][i][j];
            if (DIST[1][i][j]-DIST[0][i][j] < KCOST[i][j])
                KCOST[i][j] = DIST[1][i][j]-DIST[0][i][j];
        }
    }

    int ret = INF;
    FOR(i,0,R) FOR(j,0,C) ret = min(ret, COST[i][j]+KCOST[i][j]);
    printf("%d\n", ret);

    return 0;
}
