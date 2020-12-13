/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: cowtour
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

const int MAXV = 150;

int N;
double ADJ[MAXV][MAXV];
double DIAM[MAXV];
double FIELD[2];

int Y[MAXV], X[MAXV];
int COMP[MAXV], ncomp;

double dist(double x1, double y1, double x2, double y2) { return sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1)); }

void DFS(int v) {
    COMP[v] = ncomp;
    FOR(i,0,N) if (cmp(ADJ[v][i],DINF) != 0 && COMP[i]==-1) DFS(i);
}

int main() {

    char S[MAXV+1];

    freopen("cowtour.in","r",stdin);freopen("cowtour.out","w",stdout);

    scanf("%d", &N);
    FOR(i,0,N) scanf("%d%d ", X+i, Y+i);

    FOR(i,0,N) FOR(j,0,N) ADJ[i][j] = DINF;
    FOR(i,0,N) {
        gets(S);
        FOR(j,0,N) if (S[j]=='1') ADJ[i][j] = dist(X[i],Y[i],X[j],Y[j]);
    }
    FOR(i,0,N) ADJ[i][i] = 0.;

    FOR(k,0,N) FOR(i,0,N) FOR(j,0,N)
        if (ADJ[i][k]+ADJ[k][j] < ADJ[i][j])
            ADJ[i][j] = ADJ[i][k]+ADJ[k][j];

    FOR(i,0,N) COMP[i] = -1;
    ncomp = 0;
    FOR(i,0,N) if (COMP[i]==-1) { DFS(i); ncomp++; }

    FOR(i,0,N) DIAM[i] = -1; FIELD[0] = FIELD[1] = -1;

    FOR(i,0,N) FOR(j,0,N) {
        if (cmp(ADJ[i][j],DINF)!=0 && DIAM[i] < ADJ[i][j])
            DIAM[i] = ADJ[i][j];
        if (DIAM[i] > FIELD[COMP[i]])
            FIELD[COMP[i]] = DIAM[i];
    }

    double ret = DINF;
    FOR(i,0,N) FOR(j,0,N) if (COMP[i]!=COMP[j]) {
        double d = DIAM[i]+DIAM[j]+dist(X[i],Y[i],X[j],Y[j]);
        d = max(d,FIELD[COMP[i]]);
        d = max(d,FIELD[COMP[j]]);
        ret = min(ret,d);
    }

    printf("%.6lf\n", ret);

    return 0;
}
