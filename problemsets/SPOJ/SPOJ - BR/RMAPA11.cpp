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
#include <map>

using namespace std;

typedef pair<int,int> PII;

int N, M;
vector<int> adj[505], d[505];
int D[505], in[505];

int main() {

    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back(b);
        d[a].push_back(c);
        adj[b].push_back(a);
        d[b].push_back(c);
    }
    for (int i = 1; i <= N; i++) D[i] = 1000;
    D[1] = 0;
    int ret = 0;
    priority_queue<PII, vector<PII>, greater<PII> > q;
    q.push(make_pair(0, 1));
    while (!q.empty()) {
        int u = q.top().second; q.pop();
        if (in[u]) continue;
        in[u] = 1;
        ret += D[u];
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i], c = d[u][i];
            if (c < D[v]) D[v] = c, q.push(make_pair(c, v));
        }
    }
    printf("%d\n", ret);

    return 0;
}
