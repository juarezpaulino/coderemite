/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <queue>
#include <map>
#include <string.h>


using namespace std;

int n, m, mapa[15][15], mov, est[15][15];

int BFS(int x, int y) {
    int u, v;
    queue<pair<int, int> >q;
    q.push(make_pair(x, y)); est[y][x] = 0;
    while (!q.empty()) {
        u = q.front().first; v = q.front().second;
        if (mapa[v][u]==0) return est[v][u]; q.pop();
        if (v > 0 && est[v-1][u]==-1 && mapa[v-1][u]!=2) { 
            est[v-1][u] = est[v][u]+1; q.push(make_pair(u, v-1));
        }
        if (u > 0 && est[v][u-1]==-1 && mapa[v][u-1]!=2) { 
            est[v][u-1] = est[v][u]+1; q.push(make_pair(u-1, v));
        }
        if (v+1 < n && est[v+1][u]==-1 && mapa[v+1][u]!=2) { 
            est[v+1][u] = est[v][u]+1; q.push(make_pair(u, v+1));
        }
        if (u+1 < m && est[v][u+1]==-1 && mapa[v][u+1]!=2) { 
            est[v][u+1] = est[v][u]+1; q.push(make_pair(u+1, v));
        }
    }
}


int main() {
    
    register int i, j, x, y;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) for (j = 0; j < m; j++) {
        scanf("%d", &mapa[i][j]); if (mapa[i][j]==3) y = i, x = j;
    }
    memset(est, -1, sizeof(est));
    printf("%d\n", BFS(x, y));
    return 0;
}

