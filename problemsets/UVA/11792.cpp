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
#include <set>

using namespace std;

int N;
int D[10101], C[10101];
vector<int> adj[10101];
vector<int> imp;
set<int> in;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int M;
        scanf("%d %d", &N, &M);
        for (int i = 1; i <= N; i++) adj[i].clear(), C[i] = 0;
        while (M--) {
            int u = -1, v;
            while (scanf("%d", &v)) {
                if (v == 0) break;
                C[v]++;
                if (u != -1) adj[u].push_back(v), adj[v].push_back(u);
                u = v;
            }
        }
        imp.clear(); in.clear();
        for (int k = 1; k <= N; k++) if (C[k] >= 2) imp.push_back(k), in.insert(k);
        int pret, ret = 1<<30;
        for (int i = 0; i < imp.size(); i++) {
            int k = imp[i];
            for (int i = 1; i <= N; i++) D[i] = -1;
            queue<int> q;
            q.push(k);
            D[k] = 0;
            int ans = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (in.count(u)) ans += D[u];
                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u][i];
                    if (D[v]==-1) {
                        D[v] = D[u]+1;
                        q.push(v);
                    }
                }
            }
            if (ans < ret) { ret = ans; pret = k; }
        }
        printf("Krochanska is in: %d\n", pret);
    }

    return 0;
}
