/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define FOR(i,m,n) for (int (i)=(m);(i)<(n);(i)++)
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

using namespace std;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int,int> PII;
typedef signed long long i64;

#define EPS 1E-14
#define INF 0x3F3F3F3F
#define DINF 1E16
#define NULO -1
#define PI 3.1415926535897932384626433832795

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline string ITOA(int a) {
    char c[500]; sprintf(c, "%d", (a)); return string(c);
}

/******************************************************************************/

const int MAXV = 50*50;
const int MAXE = 50;

int N;                                   // # of left and right nodes.
int PAR[MAXV];                              // par[] - pair relationship.
int MATCH;                                  // maximum matching.

int adj[MAXV][MAXE], nadj[MAXV];
int disc[MAXV];

int augment(int u, int c) {
    for (int i = 0; i < nadj[u]; i++) {
        int v = adj[u][i];
        if (disc[v] != c) {
            disc[v] = c;
            if (PAR[v]==-1 || augment(PAR[v], c))
                return (PAR[v]=u, PAR[u]=v, 1);
        }
    }
    return 0;
}

int bpm() {
    MATCH = 0;
    for (int i = 0; i < N; i++) disc[i] = PAR[i] = -1;
    for (int i = 0, c = 0; i < N; i++, c++) if (nadj[i] && PAR[i]==-1)
        MATCH += augment(i, c);
    return MATCH;
}


int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1, -1, 0, 1, 0 };
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2, 0, 1, 0, -1 };


int main() {

    int R, C;
    int MAT[100][100];
    int id = 1;
    while (1) {
        scanf("%d %d", &R, &C);
        if (!R && !C) break;
        FOR(i,0,R) FOR(j,0,C) scanf("%d", &MAT[i][j]);
        N = R*C;
        FOR(i,0,N) nadj[i] = 0;
        FOR(i,0,R) FOR(j,0,C) if (MAT[i][j] >= 0) {
            for (int k = 0; k < 12; k++) if (MAT[i][j]&(1<<k)) {
                int ny = i+dy[k], nx = j+dx[k];
                if (ny < 0 || ny >= R || nx < 0 || nx >= C || MAT[ny][nx]<0) continue;
                adj[i*C+j][nadj[i*C+j]++] = ny*C+nx;
                adj[ny*C+nx][nadj[ny*C+nx]++] = i*C+j;
            }
        }

        printf("%d. %d\n", id++, bpm());
    }

    return 0;
}
