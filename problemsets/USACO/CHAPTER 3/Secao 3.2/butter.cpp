/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: butter
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

const int MAXP = 800;

int COW[MAXP];
int ADJ[MAXP][MAXP], W[MAXP][MAXP], NADJ[MAXP];
int DISC[MAXP], DIST[MAXP];
int N, P, C;

int dijkstra(int s) {
    int ret = 0;
    priority_queue<PII> q;
    FOR(i,0,P) DISC[i] = 0, DIST[i] = INF;
    q.push(MP(-(DIST[s] = 0),s));
    while (!q.empty()) {
        int u = q.top().SE; q.pop();
        if (DISC[u]) continue;
        DISC[u] = 1;
        ret += DIST[u]*COW[u];
        FOR(i,0,NADJ[u]) {
            int v = ADJ[u][i], d = DIST[u]+W[u][i];
            if (d < DIST[v]) q.push(MP(-(DIST[v] = d),v));
        }
    }
    return ret;
}

int main() {

    freopen("butter.in","r",stdin);freopen("butter.out","w",stdout);

    scanf("%d %d %d", &N, &P, &C);
    FOR(i,0,N) { int c; scanf("%d", &c); COW[c-1]++; }
    FOR(i,0,C) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c); u--; v--;
        ADJ[u][NADJ[u]] = v; W[u][NADJ[u]++] = c;
        ADJ[v][NADJ[v]] = u; W[v][NADJ[v]++] = c;
    }

    int ret = INF;
    FOR(i,0,P) {
        int v = dijkstra(i);
        ret = min(ret, v);
    }

    printf("%d\n", ret);

    return 0;
}
