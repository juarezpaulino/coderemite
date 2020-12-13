/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;


int main() {

    int N, K;
    int T[10];
    while (scanf("%d %d ", &N, &K) != EOF) {
        for (int i = 0; i < N; i++) scanf("%d ", T+i);
        vector<int> adj[N*100], custo[N*100], P[N];
        char S[1010];
        int x;
        for (int i = 0; i < N; i++) {
            gets(S);
            istringstream is(S);
            while (is >> x) {
                int k = P[i].size();
                if (k) {
                    int u = i*100 + P[i][k-1];
                    int v = i*100 + x;
                    int c = (x-P[i][k-1]) * T[i];
                    adj[u].push_back(v); custo[u].push_back(c);
                    adj[v].push_back(u); custo[v].push_back(c);
                }
                P[i].push_back(x);
            }
        }
        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) {
            int k1 = 0, k2 = 0;
            while (k1 < P[i].size() && k2 < P[j].size()) {
                if (P[i][k1] == P[j][k2]) {
                    int u = i*100 + P[i][k1];
                    int v = j*100 + P[j][k2];
                    adj[u].push_back(v); custo[u].push_back(60);
                    adj[v].push_back(u); custo[v].push_back(60);
                    k1++; k2++;
                }
                else if (P[i][k1] < P[j][k2]) k1++;
                else k2++;
            }
        }
        priority_queue<PII> q;
        int tree[N*100], dist[N*100];
        memset(tree, 0, sizeof(tree));
        memset(dist, 0x3F3F3F3F, sizeof(tree));
        for (int i = 0; i < N; i++) if (P[i][0] == 0) q.push(make_pair(dist[i*100] = 0, i*100));
        int u = -1;
        while (!q.empty()) {
            u = q.top().second; q.pop();
            if (tree[u]) continue;
            tree[u] = 1;
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i], c = custo[u][i];
                if (dist[v] > dist[u]+c)
                    q.push(make_pair(-(dist[v] = dist[u]+c), v));
            }
        }
        int d = 0x3F3F3F3F;
        for (int i = 0; i < N; i++) d = min(d, dist[i*100+K]);
        if (d != 0x3F3F3F3F) printf("%d\n", d);
        else puts("IMPOSSIBLE");
    }

    return 0;
}
