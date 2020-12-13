/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

const int INF = 1<<29;


int main() {

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        vector<int> adj[30];
        vector<char> type[30];
        vector<int> cost[30];
        char A, B, C, D;
        for (int i = 0; i < N; i++) {
            int c;
            scanf(" %c %c %c %c %d", &A, &B, &C, &D, &c);
            int u = C-'A', v = D-'A';
            adj[v].push_back(u); cost[v].push_back(c); type[v].push_back((A=='Y')?0:1);
            if (B=='B') {
                adj[u].push_back(v); cost[u].push_back(c); type[u].push_back((A=='Y')?0:1);
            }
        }

        int s, t;
        scanf(" %c %c ", &A, &B);
        s = A-'A'; t = B-'A';
        int ret = INF;
        vector<int> w;

        for (int k = 0; k < 26; k++) {
            int ds = INF, dt = INF;
            {
                char marc[26];
                int dist[26];
                priority_queue<pair<int,int> >q;
                for (int i = 0; i < 26; i++) dist[i] = INF, marc[i] = 0;
                q.push(make_pair(-(dist[k] = 0), k));
                while (!q.empty()) {
                    int u = q.top().second; q.pop();
                    if (marc[u]) continue;
                    marc[u] = 1;
                    if (u == s) break;
                    for (int i = 0; i < adj[u].size(); i++) {
                        int v = adj[u][i], c = cost[u][i];
                        if (type[u][i]==1) continue;
                        if (dist[v] > dist[u]+c)
                            q.push(make_pair(-(dist[v] = dist[u]+c), v));
                    }
                }
                if (marc[s]) ds = dist[s];
            }
            {
                char marc[26] = {0};
                int dist[26];
                priority_queue<pair<int,int> >q;
                for (int i = 0; i < 26; i++) dist[i] = INF, marc[i] = 0;
                q.push(make_pair(-(dist[k] = 0), k));
                while (!q.empty()) {
                    int u = q.top().second; q.pop();
                    if (marc[u]) continue;
                    marc[u] = 1;
                    if (u == t) break;
                    for (int i = 0; i < adj[u].size(); i++) {
                        int v = adj[u][i], c = cost[u][i];
                        if (type[u][i]==0) continue;
                        if (dist[v] > dist[u]+c)
                            q.push(make_pair(-(dist[v] = dist[u]+c), v));
                    }
                }
                if (marc[t]) dt = dist[t];
            }
            if (ds+dt < ret) {
                ret = ds+dt;
                w.clear();
                w.push_back(k);
            }
            else if (ds+dt == ret) w.push_back(k);
        }

        if (ret == INF) puts("You will never meet.");
        else {
            printf("%d", ret);
            for (int i = 0; i < w.size(); i++) printf(" %c", w[i]+'A');
            putchar('\n');
        }
    }

    return 0;
}
