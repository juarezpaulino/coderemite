/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)
#define FORN(i,n) for((i)=(n)-1;(i)>=0;(i)--)
#define BE(a) ((a).begin()),((a).end())
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define FORIT(i,a) for((i)=(a).begin();(i)!=(a).end();(i)++)
#define CLR(a,v) memset((a),(v),sizeof(a))

#define MAXN 380
#define INF 0x3F3F3F3F

/* cost matrix - Setar entradas entre dois nós sem arestas com o
 * maior/menor valor das arestas dadas.
 */
int cost[MAXN][MAXN];
int m, n, max_match;
int lx[MAXN], ly[MAXN];
int xy[MAXN];
int yx[MAXN];
bool S[MAXN], T[MAXN];
int slack[MAXN];
int slackx[MAXN];
int prev[MAXN];

void init_labels() {
    int i, x, y;
    FOR(i, m) lx[i] = -INF; FOR(i, n) ly[i] = -INF;
    FOR(x, m) FOR(y, n) lx[x] = max(lx[x],cost[x][y]);
}

void update_labels() {
    int x, y, delta = INF;
    FOR(y, n) if (!T[y]) delta = min(delta,slack[y]);
    FOR(x, m) if (S[x]) lx[x]-=delta;
    FOR(y, n) if (T[y]) ly[y]+=delta;
    FOR(y, n) if (!T[y]) slack[y]-=delta;
}

void add_to_tree(int x, int prevx) {
    int y; S[x] = true; prev[x] = prevx;
    FOR(y, n) if (lx[x]+ly[y]-cost[x][y] < slack[y])
        slack[y] = lx[x]+ly[y]-cost[x][y], slackx[y] = x;
}

void augment() {
    int i;
    if (max_match == m) return;
    int x, y, root;
    int q[MAXN], wr = 0, rd = 0;
    FOR(i, n) S[i] = T[i] = false, prev[i] = -1;
    FOR(x, m) if (xy[x] == -1) {
        q[wr++] = root = x; prev[x] = -2; S[x] = true; break;
    }
    FOR(y, n) slack[y] = lx[root]+ly[y]-cost[root][y], slackx[y] = root;
    while (1) {
        while (rd < wr) {
            x = q[rd++];
            FOR(y, n) if (cost[x][y] == lx[x]+ly[y] && !T[y]) {
                if (yx[y] == -1) break;
                T[y] = true; q[wr++] = yx[y]; add_to_tree(yx[y], x);
            }
            if (y < n) break;
        }
        if (y < n) break;
        update_labels(); wr = rd = 0;
        FOR(y, n) if (!T[y] && slack[y]==0)
            if (yx[y] == -1) { x = slackx[y]; break; }
            else {
                T[y] = true;
                if (!S[yx[y]]) q[wr++] = yx[y], add_to_tree(yx[y], slackx[y]);
            }
        if (y < n) break;
    }
    if (y < n) {
        max_match++;
        for (int cx = x, cy = y, ty; cx != -2; cx = prev[cx], cy = ty)
            ty = xy[cx], yx[cy] = cx, xy[cx] = cy;
        augment();
    }
}

int hungarian() {
    int i, x, ret = 0; max_match = 0;
    FOR(i, m) xy[i] = -1; FOR(i, n) yx[i] = -1;
    init_labels(); augment();
    FOR(x, m) ret += cost[x][xy[x]];
    return ret;
}


int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}


int main() {

    int i, j, k, x, y, c, M;
    for (int t = get_int(), f = 0; t--; ) {
        (f)?putchar('\n'):(f=1);
        m = get_int(); n = get_int(); k = get_int();
        FOR(i, m) FOR(j, n) cost[i][j] = -INF; M = INF;
        FOR(i, k) x = get_int(), y = get_int(), c = -get_int(), M=min(M,c), cost[x][y] = c;
        FOR(i, m) FOR(j, n) if (cost[i][j]==-INF) cost[i][j] = M;
        printf("%d\n", -hungarian());
    }
    return 0;
}
