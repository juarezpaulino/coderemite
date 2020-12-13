/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: prime3
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

struct square { int T[5][5]; };

square S[1000], CUR;
int ns;

int SUM, F;

int G[5][5][2] = { { {1,1}, {0,2}, {0,3}, {2,1}, {0,1} },
                   { {1,4}, {2,2}, {3,2}, {0,4}, {2,0} },
                   { {2,4}, {4,1}, {3,3}, {4,3}, {3,0} },
                   { {3,4}, {1,3}, {1,0}, {4,4}, {-1,-1} },
                   { {3,1}, {2,3}, {1,2}, {4,2}, {4,0} }
                 };

bool PATTERN[11][11][11][11][11];
int FILL[5];

void add_pattern(int N, int k) {
    if (k == 5) {
        PATTERN[FILL[4]][FILL[3]][FILL[2]][FILL[1]][FILL[0]] = 1;
        return;
    }
    FILL[k] = N%10;
    add_pattern(N/10, k+1);
    FILL[k] = 10;
    add_pattern(N/10, k+1);
}

#define MAXV 100010
int PR[MAXV];
void GENPR() {
    fill(PR+2, PR+MAXV, 1);
    for (int i = 4; i < MAXV; i+=2) PR[i] = 0;
    for (i64 i = 3; i < MAXV; i+=2) if (PR[i]) {
        if (i/10000!=0 && (i/10000 + (i/1000)%10 + (i/100)%10 + (i/10)%10 + i%10)==SUM)
            add_pattern(i, 0);
        for (i64 j = i*i; j < MAXV; j += 2*i) PR[j] = 0;
    }
}

bool comp(const square &A, const square &B) {
    FOR(i,0,5) FOR(j,0,5)
        if (A.T[i][j] != B.T[i][j])
            return A.T[i][j] < B.T[i][j];
    return false;
}

void PRINT(square &A) {
    FOR(i,0,5) {
        FOR(j,0,5)
            if (A.T[i][j]==-1) printf("#");
            else printf("%d", A.T[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

bool check(int y, int x) {
    if (!PATTERN[CUR.T[y][0]][CUR.T[y][1]][CUR.T[y][2]][CUR.T[y][3]][CUR.T[y][4]]) return false;
    if (!PATTERN[CUR.T[0][x]][CUR.T[1][x]][CUR.T[2][x]][CUR.T[3][x]][CUR.T[4][x]]) return false;
    if (y==x && !PATTERN[CUR.T[0][0]][CUR.T[1][1]][CUR.T[2][2]][CUR.T[3][3]][CUR.T[4][4]]) return false;
    if (y==4-x && !PATTERN[CUR.T[4][0]][CUR.T[3][1]][CUR.T[2][2]][CUR.T[1][3]][CUR.T[0][4]]) return false;
    return true;
}

void fill(const int y, const int x) {

    if (y == -1 && x == -1) {
        S[ns++] = CUR;
        return;
    }

    int b = (!y&&!x) ? F : (!y || !x) ? 1 : 0;
    int e = (!y&&!x) ? F : 9;

    for (int i = b; i <= e; i++) {
        CUR.T[y][x] = i;
        if (check(y, x)) fill(G[y][x][0], G[y][x][1]);
        CUR.T[y][x] = 10;
    }
}

int main() {

    freopen("prime3.in","r",stdin);freopen("prime3.out","w",stdout);

    scanf("%d %d", &SUM, &F);

    GENPR();

    FOR(i,0,5) FOR(j,0,5) CUR.T[i][j] = 10;
    fill(0, 0);

    if (!ns) { puts("NONE"); return 0; }

    sort(S, S+ns, comp);

    FOR(k,0,ns) {
        FOR(i,0,5) {
            FOR(j,0,5) putchar('0'+S[k].T[i][j]);
            putchar('\n');
        }
        if (k != ns-1) putchar('\n');
    }

    return 0;
}
