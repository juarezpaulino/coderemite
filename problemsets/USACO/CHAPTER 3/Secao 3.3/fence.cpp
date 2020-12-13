/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: fence
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

const int MAXV = 500;

int ADJ[MAXV][MAXV];
int DEG[MAXV];
char DISC[MAXV];
list<int> C;

int F;

void DFS(int u) {
    DISC[u] = 1;
    FOR(i,0,MAXV) if (ADJ[u][i] && !DISC[i]) DFS(i);
}

bool connected() {
    FOR(i,0,MAXV) DISC[i] = 0;
    FOR(i,0,MAXV) if (DEG[i]) { DFS(i); break; }
    FOR(i,0,MAXV) if (DEG[i] && !DISC[i]) return 0;
    return 1;
}

void euler(int u) {
    FOR(i,0,MAXV) if (ADJ[u][i]) {
        ADJ[u][i]--, ADJ[i][u]--, DEG[u]--, DEG[i]--;
        euler(i);
    }
    C.push_front(u);
}


int main() {

    freopen("fence.in","r",stdin);freopen("fence.out","w",stdout);

    scanf("%d", &F);
    FOR(i,0,F) {
        int u, v; scanf("%d%d", &u, &v);
        u--; v--;
        ADJ[u][v]++; ADJ[v][u]++; DEG[u]++; DEG[v]++;
    }

    int m1 = -1, m2 = -1;
    FOR(i,0,MAXV) {
        if (DEG[i] && m1 == -1) m1 = i;
        if (DEG[i]%2 && m2 == -1) m2 = i;
    }

    (m2==-1) ? euler(m1) : euler(m2);

    FORIT(it, ALL(C)) printf("%d\n", *it+1);

    return 0;
}
