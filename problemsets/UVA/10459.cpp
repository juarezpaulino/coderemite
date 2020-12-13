/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[5050];
int deg[5050];


int main() {

    int N;
    while (scanf("%d", &N) != EOF) {
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            int k; scanf("%d", &k);
            deg[i] = k;
            while (k--) {
                int x; scanf("%d", &x);
                adj[i].push_back(x);
            }
        }
        vector<int> best, worst;
        queue<int> q;
        int l = 0;
        for (int i = 1; i <= N; i++) if (deg[i]==1) q.push(i), l++;
        while (!q.empty()) {
            int nl = 0;
            best.clear();
            while (l--) {
                int u = q.front(); q.pop();
                best.push_back(u);
                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u][i];
                    if (--deg[v]==1) nl++, q.push(v);
                }
            }
            l = nl;
        }
        while (q.size()) q.pop();
        for (int i = 1; i <= N; i++) deg[i] = 0;
        l = 0;
        for (int i = 0; i < best.size(); i++) q.push(best[i]), deg[best[i]] = 1, l++;
        while (!q.empty()) {
            int nl = 0;
            worst.clear();
            while (l--) {
                int u = q.front(); q.pop();
                worst.push_back(u);
                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u][i];
                    if (!deg[v]) nl++, q.push(v), deg[v] = 1;
                }
            }
            l = nl;
        }
        sort(best.begin(), best.end());
        sort(worst.begin(), worst.end());
        printf("Best Roots  :");
        for (int i = 0; i < best.size(); i++) printf(" %d", best[i]);
        printf("\nWorst Roots :");
        for (int i = 0; i < worst.size(); i++) printf(" %d", worst[i]);
        putchar('\n');
    }

    return 0;
}
