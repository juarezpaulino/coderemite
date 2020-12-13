/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int V[1010];
vector<int> adj[1010];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int P, D;
        scanf("%d %d", &P, &D);
        for (int i = 0; i < P; i++) adj[i].clear(), V[i] = (1<<30);
        for (int i = 0; i < D; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        queue<int> q;
        V[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (V[v] == 1<<30) {
                    V[v] = V[u]+1;
                    q.push(v);
                }
            }
        }
        for (int i = 1; i < P; i++) printf("%d\n", V[i]);
        if (T) putchar('\n');
    }

    return 0;
}
