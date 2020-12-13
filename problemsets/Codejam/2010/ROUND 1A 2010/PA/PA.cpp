/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
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

const int MAXV = 60;

int N, K;
char M1[MAXV][MAXV], M2[MAXV][MAXV], M3[MAXV][MAXV];

int dy[] = { 1, 0, 1, 1 };
int dx[] = { 0, 1, -1, 1 };

inline bool in_bound(int y, int x) { return y >= 0 && x >= 0 && y < N && x < N; }

bool V1() {
    FOR(i,0,N) FOR(j,0,N) if (M3[i][j]=='R') {
        FOR(k,0,4) {
            int s = 0;
            int y = i; int x = j;
            while (in_bound(y,x) && M3[y][x]=='R') {
                s++; y = y+dy[k]; x = x+dx[k];
            }
            if (s >= K) return true;
        }
    }
    return false;
}

bool V2() {
    FOR(i,0,N) FOR(j,0,N) if (M3[i][j]=='B') {
        FOR(k,0,4) {
            int s = 0;
            int y = i; int x = j;
            while (in_bound(y,x) && M3[y][x]=='B') {
                s++; y = y+dy[k]; x = x+dx[k];
            }
            if (s >= K) return true;
        }
    }
    return false;
}



int main() {
    
//	freopen("A.in","r",stdin);
//	freopen("A-small-practice.in","r",stdin);freopen("A-small-practice.out","w",stdout);
//	freopen("A-large-practice.in","r",stdin);freopen("A-large-practice.out","w",stdout);
//	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
//	freopen("A-small-attempt1.in","r",stdin);freopen("A-small-attempt1.out","w",stdout);
//	freopen("A-small-attempt2.in","r",stdin);freopen("A-small-attempt2.out","w",stdout);
	freopen("A-large.in","r",stdin);freopen("A-large.ans","w",stdout);

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        // Read input.
        scanf("%d %d", &N, &K);
        FOR(i,0,N) scanf("%s", M1[i]);
        
        // Rotate M1 to M2
        FOR(i,0,N) FOR(j,0,N) M2[j][i] = M1[i][j];
        FOR(i,0,N) reverse(M2[i], M2[i]+N);
        
        // Fall the table on M3.
        FOR(i,0,N) FOR(j,0,N) M3[i][j] = '.';
        FOR(j,0,N) for (int i = N-1; i >= 0; i--) if (M2[i][j]!='.') {
            int k; for (k = i+1; k < N && M3[k][j]=='.'; k++);
            M3[k-1][j] = M2[i][j];
        }
        
        bool v1 = V1();
        bool v2 = V2();
                        
        // Prints result.
        if (!v1 && !v2) printf("Case #%d: Neither\n", tc);
        else if (v1 && !v2) printf("Case #%d: Red\n", tc);
        else if (!v1 && v2) printf("Case #%d: Blue\n", tc);
        else printf("Case #%d: Both\n", tc);

    }

	return 0;
}
