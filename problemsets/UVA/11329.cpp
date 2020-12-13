/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <map>
#include <string>

using namespace std;

struct state {
    unsigned short M, p, F;
    state(int M = 0, int p = 0, int F = 0) : M(M), p(p), F(F) {}
    bool operator<(const state &B) const {
        if (p != B.p) return p < B.p;
        if (F != B.F) return F < B.F;
        return M < B.M;
    }
};

int D[1<<16][16][1<<6];

//      4
//  1   0   3   5
//      2
//      5
// 0 - topo
// 2 - frente
// 1 - esquerda
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };
int dd[4][6] =  {
                    { 2, 1, 5, 3, 0, 4 },
                    { 3, 0, 2, 5, 4, 1 },
                    { 4, 1, 0, 3, 5, 2 },
                    { 1, 5, 2, 0, 4, 3 }
                };

void generate() {
    queue<state> q;
    for (int i = 0; i < 16; i++) {
        D[0][i][63] = 1;
        q.push(state(0,i,63));
    }
    while (!q.empty()) {
        state u = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = u.p/4+dy[i];
            int nx = u.p%4+dx[i];
            if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
            state v = u;
            v.p = ny*4+nx;
            v.F = 0;
            for (int j = 0; j < 6; j++) if (u.F&(1<<(dd[i][j]))) v.F |= 1<<j;
            if ((v.F&(1<<5)) && (v.M&(1<<(ny*4+nx)))==0) {
                v.F ^= 1<<5;
                v.M |= 1<<(ny*4+nx);
            }
            else if ((v.F&(1<<5))==0 && (v.M&(1<<(ny*4+nx)))) {
                v.F |= 1<<5;
                v.M ^= 1<<(ny*4+nx);
            }

            if (D[v.M][v.p][v.F] == 0) {
                D[v.M][v.p][v.F] = D[u.M][u.p][u.F] + 1;
                q.push(v);
            }
        }

    }
}


int main() {

    generate();
    int T;
    scanf("%d ", &T);
    while (T--) {
        state S;
        char s[10];
        for (int i = 0; i < 4; i++) {
            scanf("%s", s);
            for (int j = 0; j < 4; j++) {
                if (s[j]=='D') S.p = i*4+j, s[j] = '0';
                if (s[j]=='X') S.M |= 1<<(i*4+j);
            }
        }
        int ret = D[S.M][S.p][S.F];
        if (ret == 0) puts("impossible");
        else printf("%d\n", ret-2);
    }

    return 0;
}
