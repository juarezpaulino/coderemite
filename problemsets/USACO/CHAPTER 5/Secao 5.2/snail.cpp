/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: snail
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

int N, B;
char mapa[130][130];
char DISC[130][130];
int maxi;

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

void DFS(int k, int y, int x, int d) {
    DISC[y][x] = 1;

    int ny = y + dy[d], nx = x + dx[d];
    if (DISC[ny][nx]) {
        maxi = max(maxi, k);
        DISC[y][x] = 0;
        return;
    }

    if (ny < 0 || ny >= N || nx < 0 || nx >= N || mapa[ny][nx]) {
        // Change dir.
        bool found = false;
        FOR(nd,0,4) {
            ny = y + dy[nd], nx = x + dx[nd];
            if (ny < 0 || ny >= N || nx < 0 || nx >= N ||
                mapa[ny][nx] || DISC[ny][nx]) continue;
            found = true;
            DFS(k+1,ny,nx,nd);
        }
        if (!found) maxi = max(maxi, k);
    }
    else DFS(k+1,ny,nx,d);

    DISC[y][x] = 0;
}


int main() {

    freopen("snail.in","r",stdin);freopen("snail.out","w",stdout);

    scanf("%d %d ", &N, &B);
    FOR(i,0,B) {
        char c; int r;
        scanf("%c%d ", &c, &r); c-='A'; r--;
        mapa[r][c] = 1;
    }

    maxi = 1;
    DFS(1,0,0,0);
    DFS(1,0,0,1);

    printf("%d\n", maxi);

    return 0;
}
