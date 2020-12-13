/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

unsigned short marc[1010][1010];
int dist[1010][1010];
unsigned short MAPA[1010][1010], id = 1;
int R, C;
int sy, sx, ty, tx;

int main() {

    while (scanf("%d    %d", &R, &C)) {
        if (!(R|C)) break;
        int K; scanf("%d", &K);
        while (K--) {
            int r, k, c;
            scanf("%d %d", &r, &k);
            for (int i = 0; i < k; i++) {
                scanf("%d\n", &c);
                MAPA[r][c] = id;
            }
        }
        scanf("%d %d %d %d", &sy, &sx, &ty, &tx);
        queue<PII> q;
        marc[sy][sx] = id;
        dist[sy][sx] = 0;
        q.push(PII(sy,sx));
        while (!q.empty()) {
            PII u = q.front(); q.pop();
            if (u.first == ty && u.second == tx) break;
            for (int i = 0; i < 4; i++) {
                int ny = u.first+dy[i], nx = u.second+dx[i];
                if (ny < 0 || nx < 0 || ny >= R || nx >= C || MAPA[ny][nx]==id || marc[ny][nx]==id) continue;
                PII v(ny,nx);
                dist[ny][nx] = dist[u.first][u.second] + 1;
                marc[ny][nx] = id;
                q.push(v);
            }
        }
        printf("%d\n", dist[ty][tx]);
        id++;
    }

    return 0;
}
