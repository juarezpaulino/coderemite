/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: castle
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

const int MAXV = 50;

int N, M;
int MAPA[MAXV][MAXV];
int COMP[MAXV][MAXV], ROOM[MAXV*MAXV], ncomp;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int WALL[] = { 1, 2, 3, 0 };
inline bool in_bound(int y, int x) { return y >= 0 && x >= 0 && y < M && x < N; }

void DFS(int y, int x) {
    COMP[y][x] = ncomp;
    ROOM[ncomp]++;
    FOR(k,0,4) if (in_bound(y+dy[k], x+dx[k])) {
        int ny = y+dy[k], nx = x+dx[k];
        if (COMP[ny][nx]!=-1) continue;
        if (MAPA[y][x]&(1<<WALL[k])) continue;
        DFS(ny, nx);
    }
}

int main() {

    freopen("castle.in","r",stdin);freopen("castle.out","w",stdout);

    scanf("%d %d", &N, &M);

    FOR(i,0,M) FOR(j,0,N) COMP[i][j] = -1, scanf("%d", &MAPA[i][j]);

    ncomp = 0;
    FOR(i,0,M) FOR(j,0,N) if (COMP[i][j]==-1) { DFS(i,j); ncomp++; }

    int larger = 0;
    FOR(i,0,ncomp) larger = max(larger, ROOM[i]);

    int maxi = 0, my, mx;
    char dir;
    for (int j = N-1; j >= 0; j--) FOR(i,0,M) for (int k = 1; k >= 0; k--)
        if (in_bound(i+dy[k], j+dx[k])) {
            int y = i+dy[k], x = j+dx[k];
            if (COMP[i][j] != COMP[y][x] &&
                ROOM[COMP[i][j]]+ROOM[COMP[y][x]] >= maxi) {
                maxi = ROOM[COMP[i][j]]+ROOM[COMP[y][x]];
                my = i; mx = j;
                dir = (k==0) ? 'N' : 'E';
            }
        }

    printf("%d\n%d\n%d\n%d %d %c\n", ncomp, larger, maxi, my+1, mx+1, dir);

    return 0;
}
