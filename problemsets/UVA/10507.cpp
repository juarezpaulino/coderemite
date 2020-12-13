/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int main() {

    int N, M;
    while (scanf("%d", &N) != EOF) {
        scanf("%d", &M);
        char S[5];
        scanf("%s", S);
        vector<int> adj[256];
        int D[256];
        for (int i = 0; i < 256; i++) D[i] = 3;
        queue<int> q;
        q.push(S[0]); q.push(S[1]); q.push(S[2]);
        D[S[0]] = D[S[1]] = D[S[2]] = 0;
        for (int i = 0; i < M; i++) {
            scanf("%s", S);
            adj[S[0]].push_back(S[1]);
            adj[S[1]].push_back(S[0]);
        }
        int ret = -1;
        while (!q.empty()) {
            ret++;
            int K = q.size();
            for (int k = 0; k < K; k++) {
                int u = q.front(); q.pop();
                N--;
                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u][i];
                    if (D[v] <= 0) continue;
                    if (--D[v]==0) q.push(v);
                }
            }
        }
        if (N) puts("THIS BRAIN NEVER WAKES UP");
        else printf("WAKE UP IN, %d, YEARS\n", ret);
    }

    return 0;
}
