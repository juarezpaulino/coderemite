/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: frameup
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

char F[40][40];
int H, W;
bool in[30];
int XMIN[30], XMAX[30], YMIN[30], YMAX[30];

int N;
int G[30][30];
char ret[30];

void DFS(int k) {
    if (k == N) {
        ret[k] = 0;
        puts(ret);
        return;
    }
    FOR(i,0,26) if (in[i]) {
        bool ok = true;
        FOR(j,0,26) if (in[j] && G[i][j]) { ok = false; break; }
        if (ok) {
            in[i] = 0;
            ret[k] = i+'A';
            DFS(k+1);
            in[i] = 1;
        }
    }
}


int main() {

    freopen("frameup.in","r",stdin);freopen("frameup.out","w",stdout);

    scanf("%d %d ", &H, &W);

    FOR(i,0,H) scanf("%s ", F[i]);

    // Find frame bound.
    CLR(in,0); CLR(XMIN, INF); CLR(YMIN, INF); CLR(XMAX, -1); CLR(YMAX, -1);
    N = 0;
    FOR(i,0,H) FOR(j,0,W) if (F[i][j]!='.') {
        int k = F[i][j]-'A';
        if (!in[k]) { in[k] = 1; N++; }
        XMIN[k] = min(XMIN[k], j); YMIN[k] = min(YMIN[k], i);
        XMAX[k] = max(XMAX[k], j); YMAX[k] = max(YMAX[k], i);
    }

    // Build partial order graph.
    FOR(k,0,26) if (in[k]) {
        FOR(j,XMIN[k],XMAX[k]+1) if (F[YMIN[k]][j]!='A'+k) G[F[YMIN[k]][j]-'A'][k] = 1;
        FOR(j,XMIN[k],XMAX[k]+1) if (F[YMAX[k]][j]!='A'+k) G[F[YMAX[k]][j]-'A'][k] = 1;
        FOR(i,YMIN[k],YMAX[k]+1) if (F[i][XMIN[k]]!='A'+k) G[F[i][XMIN[k]]-'A'][k] = 1;
        FOR(i,YMIN[k],YMAX[k]+1) if (F[i][XMAX[k]]!='A'+k) G[F[i][XMAX[k]]-'A'][k] = 1;
    }

    // Compute Answers.
    DFS(0);

    return 0;
}
