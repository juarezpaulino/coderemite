/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int N, M;
    vector<int> adj[50505];
    int in[50505] = {0};
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        in[b]++;
    }
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 0; i < N; i++) if (!in[i]) q.push(i);
    vector<int> ret;
    while (!q.empty()) {
        int u = q.top(); q.pop();
        ret.push_back(u);
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            in[v]--;
            if (!in[v]) q.push(v);
        }
    }
    if (ret.size() != N) puts("*");
    else for (int i = 0; i < N; i++) printf("%d\n", ret[i]);

    return 0;
}
