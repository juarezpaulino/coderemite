/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/*
 ID: juarezp1
 PROG: starry
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

int H, W;
char MAPA[150][150];

char FRAME[50][150][150];
char LABEL[50];
int nframe;

int xmin, xmax, ymin, ymax;
int h, w;
int DISC[150][150], id = 1;

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

char CUR[150][150];

void rotate(char T[150][150], char S[150][150]) {
    FOR(i,0,h) FOR(j,0,w)
        T[j][i] = S[i][w-j-1];
}

void mirror(char T[150][150], char S[150][150]) {
    FOR(i,0,h) FOR(j,0,w)
        T[i][j] = S[i][w-j-1];
}

void PRINT(char A[150][150]) {
    FOR(i,0,h) {
        FOR(j,0,w) putchar(A[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

char check() {
    char CP[150][150];
//    cout << "CUR" << endl;
//    PRINT(CUR);
    FOR(k,0,4) {
        memcpy(CP, CUR, sizeof(CP));
        CLR(CUR,0);
        rotate(CUR, CP); swap(w,h);
//        cout << "ROTATE\n";
//        PRINT(CUR);
        FOR(i,0,nframe)
            if (!memcmp(CUR,FRAME[i],sizeof(CUR)))
                return LABEL[i];
    }
    memcpy(CP, CUR, sizeof(CP));
    CLR(CUR,0);
    mirror(CUR, CP);
    FOR(k,0,4) {
        memcpy(CP, CUR, sizeof(CP));
        CLR(CUR,0);
        rotate(CUR, CP); swap(w,h);
        FOR(i,0,nframe)
            if (!memcmp(CUR,FRAME[i],sizeof(CUR)))
                return LABEL[i];
    }
    memcpy(CP, CUR, sizeof(CP));
    CLR(CUR,0);
    mirror(CUR, CP);

    // New frame found.

    memcpy(FRAME[nframe], CUR, sizeof(CUR));
    char ret = nframe+'a';
    int pos = nframe;
    nframe++;
    return LABEL[pos] = ret;
}

void DFS(int y, int x) {
    DISC[y][x] = id;
    ymin = min(ymin, y); xmin = min(xmin, x);
    ymax = max(ymax, y); xmax = max(xmax, x);
    FOR(i,0,8) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
        if (DISC[ny][nx]!=0 || MAPA[ny][nx]!='1') continue;
        DFS(ny, nx);
    }
}

int main() {

    freopen("starry.in","r",stdin);freopen("starry.out","w",stdout);

    scanf("%d %d ", &W, &H);
    FOR(i,0,H) scanf("%s ", MAPA[i]);

    // FloodFill
    CLR(DISC,0);
    FOR(i,0,H) FOR(j,0,W) if (!DISC[i][j] && MAPA[i][j]=='1') {
        xmin = ymin = INF; xmax = ymax = -1;
        DFS(i,j);
        //printf("%d %d %d %d\n", ymin, xmin, ymax, xmax);

        CLR(CUR,0);
        FOR(o,ymin,ymax+1) FOR(p,xmin,xmax+1) {
            if (DISC[o][p]==id)
                CUR[o-ymin][p-xmin] = '1';
            else
                CUR[o-ymin][p-xmin] = '0';
        }
        w = xmax - xmin + 1; h = ymax - ymin + 1;

        char label = check();
        FOR(o,ymin,ymax+1) FOR(p,xmin,xmax+1)
            if (DISC[o][p]==id)
                MAPA[o][p] = label;
        id++;
    }

    // Prints
    FOR(i,0,H) {
        FOR(j,0,W) putchar(MAPA[i][j]);
        putchar('\n');
    }

    return 0;
}
