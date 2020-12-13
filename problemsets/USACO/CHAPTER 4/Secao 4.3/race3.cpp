/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: race3
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

const int MAXV = 55;

int N, ADJ[MAXV][MAXV], NADJ[MAXV];
int DISC[MAXV]={0}, P[MAXV], P2[MAXV];
int NP, NP2;

void DFS(int u, int b) {
    DISC[u] = 1;
    FOR(i,0,NADJ[u]) {
        int v = ADJ[u][i];
        if (v != b && !DISC[v]) DFS(v, b);
    }
}

bool DFS2(int u) {
    DISC[u] = 2;
    FOR(i,0,NADJ[u]) {
        int v = ADJ[u][i];
        if (DISC[v]==1 || (DISC[v]!=2 && !DFS2(v))) return false;
    }
    return true;
}

int main() {

    freopen("race3.in","r",stdin);freopen("race3.out","w",stdout);

    N = 0;
    while (1) {
        int v;
        while (1) {
            scanf("%d", &v);
            if (v == N) continue;
            if (v == -2 || v == -1) break;
            ADJ[N][NADJ[N]++] = v;
        }
        if (v == -1) break;
        N++;
    }

    FOR(i,1,N-1) {
        CLR(DISC,0);
        DISC[i] = 1;
        DFS(0,-1);
        if (!DISC[N-1]) P[NP++] = i;
    }

    FOR(i,0,NP) {
        CLR(DISC,0);
        DFS(0, P[i]);
        if (DFS2(P[i])) P2[NP2++] = P[i];
    }

    printf("%d", NP);
    for (int i = 0; i < NP; i++) printf(" %d", P[i]);
    putchar('\n');

    printf("%d", NP2);
    for (int i = 0; i < NP2; i++) printf(" %d", P2[i]);
    putchar('\n');


    return 0;
}
