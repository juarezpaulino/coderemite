/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: ditch
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

const int MAXV = 202;

int N, M;

int cap[MAXV][MAXV];
int adj[MAXV][MAXV], deg[MAXV];
int prev[MAXV];

int dinic(int N, int S, int T) {
    int flow = 0;
    CLR(deg,0);
    FOR(i,0,N) FOR(j,i+1,N) if (cap[i][j] || cap[j][i])
        adj[i][deg[i]++] = j, adj[j][deg[j]++] = i;
    while(1) {
        // an augmenting path
        FOR(i,0,N) prev[i] = -1;
        queue<int> q;
        q.push(S); prev[S] = -2;
        while(!q.empty() && prev[T]==-1) {
            int u = q.front(), v; q.pop();
            FOR(i,0,deg[u]) if (prev[v=adj[u][i]]==-1 && cap[u][v])
                q.push(v), prev[v] = u;
        }
        // done?
        if (prev[T] == -1) break;
        // try finding more paths
        FOR(z,0,N) if (cap[z][T] && prev[z]!=-1) {
            int bot = cap[z][T];
            for (int v = z, u = prev[v]; u >= 0; v = u, u = prev[v])
                bot = min(bot,cap[u][v]);
            if (!bot) continue;
            cap[z][T]-=bot; cap[T][z]+=bot;
            for (int v = z, u = prev[v]; u >= 0; v = u, u = prev[v])
                cap[u][v]-=bot, cap[v][u]+=bot;
            flow+=bot;
        }
    }
    return flow;
}

int main() {

    freopen("ditch.in","r",stdin);freopen("ditch.out","w",stdout);

    scanf("%d %d", &M, &N);
    CLR(cap,0);
    FOR(i,0,M) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c); u--; v--;
        cap[u][v]+=c;
    }
    printf("%d\n", dinic(N,0,N-1));

    return 0;
}
