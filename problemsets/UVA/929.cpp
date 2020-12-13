/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
// Dijkstra algorithm with ~O(E+V) and A* heuristic
//
// - Use for large matrix graphs 0 <= N <= 10^6.
// - Use only for small edge weights (0 <= 15 <= maxW).
// - Use before start:
//      memset(nval,0,sizeof(nval));
//      D = vector<vector<int> >(M, vector<int>(N, 1<<30));
//      insert(0,0,mini=((D[0][0]=mapa[0][0])+H(0,0,M-1,N-1)));
//

typedef pair<int,int> pii;

int M, N;

const int MAXVAL = 11;
const int MAXENT = 5010;

vector<vector<bool> > vis;
vector<vector<int> > D;
vector<pii> val[MAXVAL];
int nval[MAXVAL], mini;

// A* Heuristics.
inline int H(int yi, int xi, int yf, int xf) {
    int dx = abs(xf-xi), dy = abs(yf-yi);
    int diag = min(dx,dy);
    int r = abs(dx-dy);
    return 3 * diag + 2 * r;
}

// O(1) priority_queue for small weighted edges.
int next(int &y, int &x) {
    mini = mini % MAXVAL;
    do {
        int t = 0;
        while (!nval[mini]) {
            mini = (mini + 1) % MAXVAL;
            if (++t == MAXVAL) return 0;
        }
        int i = --nval[mini];
        y = val[mini][i].first;
        x = val[mini][i].second;
    } while (!vis[y][x] && D[y][x]%MAXVAL != mini);
    return 1;
}

// Always insert k as D[y][x]+H(y,x,M-1,N-1).
inline int insert(int y, int x, int k) {
    k %= MAXVAL;
    int i = nval[k]++;
    if (nval[k] >= val[k].size()) val[k].resize(nval[k] + MAXENT);
    val[k][i].first = y; val[k][i].second = x;
}

int mapa[1010][1010];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch==EOF) return ch;
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}


int main() {

    int T;
    T = get_int();
    while (T--) {
        M = get_int(); N = get_int();
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) mapa[i][j] = get_int();
        memset(nval,0,sizeof(nval));
        D = vector<vector<int> >(M, vector<int>(N, 1<<30));
        vis = vector<vector<bool> >(M, vector<bool>(N, 0));
        insert(0,0,mini=((D[0][0]=mapa[0][0])));
        int y, x;
        while (next(y,x)) {
            if (y==M-1 && x==N-1) break;
            if (vis[y][x]) continue;
            vis[y][x] = 1;
            for (int i = 0; i < 4; i++) {
                int ny = y+dy[i], nx = x+dx[i];
                if (ny < 0 || nx < 0 || ny >= M || nx >= N || vis[ny][nx]) continue;
                int d = D[y][x]+mapa[ny][nx];
                if (D[ny][nx] > d) insert(ny,nx,(D[ny][nx]=d));
            }
        }
        printf("%d\n", D[M-1][N-1]);
    }

    return 0;
}
