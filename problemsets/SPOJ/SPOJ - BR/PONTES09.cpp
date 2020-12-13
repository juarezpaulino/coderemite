/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>


using namespace std;

vector<int> adj[1010];
vector<int> cost[1010];
char vis[1010];
int D[1010];

int main() {

    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int S, T, B;
        scanf("%d %d %d", &S, &T, &B);
        adj[S].push_back(T); cost[S].push_back(B);
        adj[T].push_back(S); cost[T].push_back(B);
    }

    for (int i = 0; i <= N+1; i++) D[i] = (1<<30);
    priority_queue<pair<int,int> > q;
    q.push(make_pair(-(D[0] = 0),0));
    while (!q.empty()) {
        int u = q.top().second; q.pop();
        if (u == N+1) break;
        if (vis[u]) continue;
        vis[u] = 0;
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i], c = D[u]+cost[u][i];
            if (D[u]+cost[u][i] < D[v])
                q.push(make_pair(-(D[v] = c),v));
        }
    }
    printf("%d\n", D[N+1]);

    return 0;
}
