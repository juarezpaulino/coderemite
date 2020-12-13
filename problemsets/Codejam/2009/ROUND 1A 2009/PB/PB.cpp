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
#define ALL(M) (M).begin(), (M).end()
#define CLR(M, v) memset(M, v, sizeof(M))
#define SI(V) (int)(V.size())
#define PB push_back
#define MP make_pair

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;

const int INF = 0x3F3F3F3F;
const i64 LINF = 0x3F3F3F3F3F3F3F3FLL;
const double EPS = 1E-14;

template<class T> T SQR(T x) { return x*x; }

////////////////////////////////////////////////////////////////////////////////

const int MAXR = 20;

int M, N;
int S[MAXR][MAXR], W[MAXR][MAXR], T[MAXR][MAXR];

i64 D[MAXR][MAXR][2][2];
int disc[MAXR][MAXR][2][2];

struct Node {
    int y, x, y0, x0, d;
    bool operator<(const Node &B) const { return d > B.d; }
};

typedef priority_queue<Node> PQ;

inline void update(PQ &q, int y, int x, int y0, int x0, i64 d) {
    if (y < 0 || y >= M || x < 0 || x >= N) return;
    if (d < D[y][x][y0][x0]) {
        D[y][x][y0][x0] = d;
        q.push((Node){y,x,y0,x0,d});
    }
}

i64 waitW(i64 t, int y, int x) {
    int s = S[y][x], w = W[y][x], t0 = T[y][x];
    t = ((t-t0)%(s+w)+(s+w))%(s+w);
    return (t >= s) ? 0 : s-t;
}

i64 waitS(i64 t, int y, int x) {
    int s = S[y][x], w = W[y][x], t0 = T[y][x];
    t = ((t-t0)%(s+w)+(s+w))%(s+w);
    return (t < s) ? 0 : s+w-t;
}

int dijkstra() {
    FOR(y,0,M) FOR(x,0,N) FOR(y0,0,2) FOR(x0,0,2)
        D[y][x][y0][x0] = LINF, disc[y][x][y0][x0] = 0;
    PQ q;
    update(q,M-1,0,1,0,0);
    while (!q.empty()) {
        Node u = q.top(); q.pop();
        int y = u.y, x = u.x, y0 = u.y0, x0 = u.x0, d = u.d;
        if (disc[y][x][y0][x0]) continue;
        disc[y][x][y0][x0] = 1;
        if (y0) {
            update(q,y+1,x,y0^1,x0,d+2);
            update(q,y,x,y0^1,x0,d+waitS(d,y,x)+1);
        }
        else {
            update(q,y-1,x,y0^1,x0,d+2);
            update(q,y,x,y0^1,x0,d+waitS(d,y,x)+1);
        }
        if (x0) {
            update(q,y,x+1,y0,x0^1,d+2);
            update(q,y,x,y0,x0^1,d+waitW(d,y,x)+1);
        }
        else {
            update(q,y,x-1,y0,x0^1,d+2);
            update(q,y,x,y0,x0^1,d+waitW(d,y,x)+1);
        }
    }
    return D[0][N-1][0][1];
}

int main() {
    
//	freopen("B.in","r",stdin);
//	freopen("B-small-practice.in","r",stdin);freopen("B-small-practice.out","w",stdout);
  freopen("B-large-practice.in","r",stdin);freopen("B-large-practice.out","w",stdout);
//	freopen("B-small-attempt0.in","r",stdin);freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);freopen("B-small-attempt1.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);freopen("B-large.ans","w",stdout);

    int TC;
    scanf("%d", &TC);
    for (int tc = 1; tc <= TC; tc++) {
        // Read input.
        scanf("%d %d", &M, &N);
        FOR(i,0,M) FOR(j,0,N) scanf("%d%d%d", &S[i][j], &W[i][j], &T[i][j]);
                
        // Prints result.
        printf("Case #%d: %d\n", tc, dijkstra());
    }

	return 0;
}
