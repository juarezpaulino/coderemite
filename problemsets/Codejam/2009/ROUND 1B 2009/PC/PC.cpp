/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>


using namespace std;

#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define ALL(M) (M).begin(), (M).end()
#define CLR(M, v) memset(M, v, sizeof(M))
#define SI(V) (int)(V.size())
#define PB push_back

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;

const int INF = 0x3F3F3F3F;
const double EPS = 1E-14;

template<class T> T SQR(T x) { return x*x; }

////////////////////////////////////////////////////////////////////////////////

const int MAXV = 25;
const int MAXVAL = 800;
const int OFFSET = 450;

string ANS[MAXV][MAXV][MAXVAL];
char disc[MAXV][MAXV][MAXVAL];
char mapa[MAXV][MAXV];
int W, Q;

struct Node { int y, x, v; };

int dy[] = {-1,0,1,0};
int dx[] = {0,-1,0,1};
inline bool in_bound(int y, int x) { return y >= 0 && x >= 0 && y < W && x < W; }


int main() {
    
//	freopen("C.in","r",stdin);
//	freopen("C-small-practice.in","r",stdin);freopen("C-small-practice.out","w",stdout);
  freopen("C-large-practice.in","r",stdin);freopen("C-large-practice.out","w",stdout);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
//	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.ans","w",stdout);

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        // Read input.
        scanf("%d %d", &W, &Q);
        FOR(i,0,W) scanf("%s", mapa[i]);
        
        // Compute answer foreach state.
        queue<Node> q;
        CLR(disc,0);
        FOR(i,0,W) FOR(j,0,W) if (mapa[i][j] >= '0' && mapa[i][j]<='9') {
            int v = mapa[i][j]-'0' + OFFSET;
            disc[i][j][v] = 1;
            ANS[i][j][v] = mapa[i][j];
            q.push((Node){i,j,v});
        }
        while (!q.empty()) {
            int y = q.front().y, x = q.front().x, v = q.front().v;
            q.pop();
            string last = ANS[y][x][v];
            FOR(i,0,4) if (in_bound(y+dy[i], x+dx[i]))
            FOR(j,0,4) if (in_bound(y+dy[i]+dy[j], x+dx[i]+dx[j])) {
                int ny = y+dy[i]+dy[j], nx = x+dx[i]+dx[j],
                    sign = (mapa[y+dy[i]][x+dx[i]] == '+' ? 1 : -1),
                    nv = v + sign*(mapa[ny][nx]-'0');
                if (nv >= 0 && nv < MAXVAL) {
                    string val = last + mapa[y+dy[i]][x+dx[i]] + mapa[ny][nx];
                    if (!disc[ny][nx][nv]) {
                        disc[ny][nx][nv] = 1;
                        ANS[ny][nx][nv] = val;
                        q.push((Node){ny,nx,nv});
                    }
                    else if (SI(ANS[ny][nx][nv]) == SI(val) && val < ANS[ny][nx][nv])
                        ANS[ny][nx][nv] = val;
                }
            }
        }
        
        // Prints result.
        printf("Case #%d:\n", tc);
        FOR(i,0,Q) {
            int q; string ret = string(500,'Z');
            scanf("%d", &q); q += OFFSET;
            FOR(i,0,W) FOR(j,0,W) if (disc[i][j][q]) {
                if (SI(ANS[i][j][q]) < SI(ret) || 
                    SI(ANS[i][j][q]) == SI(ret) && ret > ANS[i][j][q])
                    ret = ANS[i][j][q];
            }
            printf("%s\n", ret.c_str());
        }
    }

	return 0;
}
