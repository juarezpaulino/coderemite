/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: ttwo
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

const int MAXV = 10;
const int MAXD = 4;

char MAPA[MAXV+1][MAXV+1];
char DISC[MAXV][MAXV][MAXD][MAXV][MAXV][MAXD];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
inline bool in_bound(int y, int x) { return y >= 0 && x >= 0 && y < MAXV && x < MAXV; }

struct Node { int FY, FX, FD, CY, CX, CD, d; };

int BFS() {
    int FY, FX, FD, CY, CX, CD;
    FOR(i,0,MAXV) FOR(j,0,MAXV)
        if (MAPA[i][j]=='F') { FY = i; FX = j; }
        else if (MAPA[i][j]=='C') { CY = i; CX = j; }

    queue<Node> q;
    q.push((Node){FY,FX,0,CY,CX,0,0});
    DISC[FY][FX][0][CY][CX][0] = 1;
    while (!q.empty()) {
        Node u = q.front(); q.pop();

        if (u.FY==u.CY && u.FX==u.CX) return u.d;

        FY = u.FY+dy[u.FD], FX = u.FX+dx[u.FD]; FD = u.FD;
        if (!in_bound(FY, FX) || MAPA[FY][FX]=='*')
            FY = u.FY, FX = u.FX, FD = (u.FD+1)%MAXD;

        CY = u.CY+dy[u.CD], CX = u.CX+dx[u.CD]; CD = u.CD;
        if (!in_bound(CY, CX) || MAPA[CY][CX]=='*')
            CY = u.CY, CX = u.CX, CD = (u.CD+1)%MAXD;

        if (DISC[FY][FX][FD][CY][CX][CD]) continue;

        DISC[FY][FX][FD][CY][CX][CD] = 1;
        q.push((Node){FY,FX,FD,CY,CX,CD,u.d+1});
    }
    return 0;
}


int main() {

    freopen("ttwo.in","r",stdin);freopen("ttwo.out","w",stdout);

    FOR(i,0,MAXV) scanf("%s", MAPA[i]);

    CLR(DISC,0);
    int ret = BFS();

    printf("%d\n", ret);

    return 0;
}
