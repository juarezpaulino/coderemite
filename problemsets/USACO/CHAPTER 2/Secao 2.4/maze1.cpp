/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: maze1
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
const double DINF = 1E14;
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

const int MAXW = 38*2+1;
const int MAXH = 100*2+1;

char MAPA[MAXH+1][MAXW+1];
int DIST[MAXH][MAXW];
int W, H;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
inline bool in_bound(int y, int x) { return y >= 0 && x >= 0 && y < H && x < W; }
inline bool empty(int y, int x) { return MAPA[y][x]!='+' && MAPA[y][x]!='-' && MAPA[y][x]!='|'; }

struct Node { int y, x; };

int BFS() {
    int ret = 0;
    queue<Node> q;
    int y, x;

    FOR(j,0,W) {
        if (empty(0,j)) { DIST[0][j] = 0; q.push((Node){0,j}); }
        if (empty(H-1,j)) { DIST[H-1][j] = 0; q.push((Node){H-1,j}); }
    }
    FOR(i,0,H) {
        if (empty(i,0)) { DIST[i][0] = 0; q.push((Node){i,0}); }
        if (empty(i,W-1)) { DIST[i][W-1] = 0; q.push((Node){i,W-1}); }
    }

    while (!q.empty()) {
        Node u = q.front(); q.pop();
        ret = max(ret, DIST[u.y][u.x]);
        FOR(i,0,4) {
            y = u.y+dy[i]; x = u.x+dx[i];
            if (!in_bound(y,x) || !empty(y,x)) continue;
            if (DIST[y][x]!=INF) continue;
            DIST[y][x] = DIST[u.y][u.x]+1;
            q.push((Node){y,x});
        }
    }
    return ret;
}


int main() {

    freopen("maze1.in","r",stdin);freopen("maze1.out","w",stdout);

    scanf("%d %d ", &W, &H); W=2*W+1; H=2*H+1;
    FOR(i,0,H) gets(MAPA[i]);

    CLR(DIST,INF);
    int ret = BFS();

    printf("%d\n", (ret+1)/2);

    return 0;
}
