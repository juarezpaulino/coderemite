/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <string>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[110];
int deg[110] = {0};
char B[110][100];

int main() {

    int T = 1;
    int N, M;
    while (scanf("%d", &N) != EOF) {
        map<string, int> mapa;
        for (int i = 0; i < N; i++) scanf("%s", B[i]), mapa[B[i]] = i;
        scanf("%d", &M);
        for (int i = 0; i < N; i++) adj[i].clear(), deg[i] = 0;
        for (int i = 0; i < M; i++) {
            char a[100], b[100];
            scanf("%s %s", a, b);
            int u = mapa[a], v = mapa[b];
            adj[u].push_back(v);
            deg[v]++;
        }
        priority_queue<int> q;
        for (int i = 0; i < N; i++) if (!deg[i]) q.push(-i);
        vector<string> ret;
        while (!q.empty()) {
            int u = -q.top(); q.pop();
            ret.push_back(B[u]);
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                deg[v]--;
                if (!deg[v])
                    q.push(-v);
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order:", T++);
        for (int i = 0; i < ret.size(); i++) printf(" %s", ret[i].c_str());
        printf(".\n\n");
    }

    return 0;
}
