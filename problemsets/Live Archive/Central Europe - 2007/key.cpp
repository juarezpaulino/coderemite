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
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define FOR(i,m,n) for((i)=(m);(i)<(n);(i)++)
#define FORN(i,m,n) for((i)=(n)-1;(i)>=m;(i)--)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a)) 
#define TLE while(1);
#define RTE printf("%d", 1/0);

using namespace std;
typedef vector<int> VI; typedef vector<double> VD; typedef vector<string> VS;
typedef vector<vector<int> > VVI; typedef vector<vector<string> > VVS;
typedef set<int> SI; typedef set<double> SD; typedef set<string> SS;
typedef pair<int,int> PII;
typedef signed long long i64; typedef unsigned long long u64;

#define EPS 1E-14
#define INF 0x3F3F3F3F
#define DINF 1E16
#define NULO -1

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct vert {
    int i, j, b, y, r, g, d;
    vert() {}
    vert(int i, int j, int b, int y, int r, int g, int d) :
        i(i), j(j), b(b), y(y), r(r), g(g), d(d) {}
};


int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
int r, c, sy, sx;
char hash[100][100][2][2][2][2];    // x, y, b, y, r, g
char mapa[100][100];

int bfs() {    
    vert u, v;
    int k;
    queue<vert> q;
    hash[sy][sx][0][0][0][0] = 1;
    q.push(vert(sy, sx, 0, 0, 0, 0, 0));
    while (!q.empty()) {
        u = q.front(); q.pop(); if (mapa[u.i][u.j]=='X') return u.d;
        FOR(k, 0, 4) {
            v = u; v.d++; v.i = u.i+dy[k], v.j = u.j+dx[k];
            if (v.i>=0 && v.j>=0 && v.i<r && v.j<c && mapa[v.i][v.j]!='#') {
                if (mapa[v.i][v.j]=='b') v.b = 1;
                else if (mapa[v.i][v.j]=='y') v.y = 1;
                else if (mapa[v.i][v.j]=='r') v.r = 1;
                else if (mapa[v.i][v.j]=='g') v.g = 1;
                if ((mapa[v.i][v.j]=='B' && !v.b) ||
                    (mapa[v.i][v.j]=='Y' && !v.y) ||
                    (mapa[v.i][v.j]=='R' && !v.r) ||
                    (mapa[v.i][v.j]=='G' && !v.g)) continue;
                if (!hash[v.i][v.j][v.b][v.y][v.r][v.g]) {
                    hash[v.i][v.j][v.b][v.y][v.r][v.g] = 1;
                    q.push(v);
                }
            }
        }
    }
    return -1;
}


int main() {

    int i, j, k, l, m, n;

    for(;scanf("%d %d ", &r, &c), r||c;) {
        FOR(i, 0, r) FOR(j, 0, c) FOR(k, 0, 2) FOR(l, 0, 2) FOR(m, 0, 2) FOR(n, 0, 2)
            hash[i][j][k][l][m][n] = 0;
        FOR(i, 0, r) {
            scanf("%s ", mapa[i]); 
            FOR(j, 0, c) {
                if (mapa[i][j]=='*') sx = j, sy = i;
            }
        }
        k = bfs();
        if (k==-1) printf("The poor student is trapped!\n");
        else printf("Escape possible in %d steps.\n", k);
    }
    
    return 0;
}
