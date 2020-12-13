/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/***********************************************************************************************************/
/*                                 Declarations, macros, parser functions                                  */
/***********************************************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define FOR(i,m,n) for((i)=(m);(i)<(n);(i)++)
#define FORE(i,m,n) for((i)=(m);(i)<=(n);(i)++)
#define ROF(i,m,n) for((i)=(m);(i)>=(n);(i)--)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a))
#define SORT(v) sort(ALL(v))
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())


inline string ITOA(int a) {
    char c[500]; sprintf(c, "%d", (a)); return string(c);
}

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VD> VVD;
typedef vector<VS> VVS;
typedef pair<int,int> PII;
typedef signed long long i64;
typedef unsigned long long u64;

#define EPS 1E-9
#define INF 0x3F3F3F3F
#define DINF 1E16
#define NULO -1
#define PI 3.1415926535897932384626433832795

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}



int N, R, C, K;
int dy[] = { -1, 0, 1, 0};
int dx[] = { 0, 1, 0, -1};

int main() {

    int i, j, ny, nx, k, l, x, u, v;
    for (; scanf("%d %d %d %d", &N, &R, &C, &K) && N+R+C+K;) {
        VVI mapa(R, VI(C)), m2(R, VI(C));
        FOR(i,0,R) FOR(j,0,C) scanf("%d", &x), mapa[i][j] = x;
        FOR(k,0,K) {
            m2 = mapa;
            FOR(i,0,R) FOR(j,0,C) FOR(l,0,4) {
                nx = j+dx[l]; ny = i+dy[l];
                if (nx >= 0 && nx < C && ny>=0 && ny < R && mapa[ny][nx]==(mapa[i][j]+1)%N) {
                    m2[ny][nx] = mapa[i][j];
                }
            }
            mapa = m2;
        }
        FOR(u,0,R) {
            FOR(v,0,C) {
                if (v) putchar(' '); printf("%d", mapa[u][v]);
            }
            putchar('\n');
        }

    }

    return 0;
}

