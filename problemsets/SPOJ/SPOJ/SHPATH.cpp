/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <queue>

using namespace std;

typedef pair<int,int> PII;

const int INF = 0x3F3F3F3F;

int t, n, p;
char s[20], s2[20];

map<string, int> mapa;

vector< vector<PII> > adj;
vector<int> dist;
vector<bool> tree;

int main() {

    scanf("%d", &t);
    while (t--) {
        mapa.clear();
        scanf("%d", &n);
        adj = vector< vector<PII> >(n, vector<PII>());
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            mapa[s] = i;
            scanf("%d", &p);
            while (p--) {
                int x, c;
                scanf("%d %d", &x, &c);
                adj[i].push_back(PII(x-1,c));
            }
        }

        int k; scanf("%d", &k);
        while (k--) {
            dist = vector<int>(n,INF);
            tree = vector<bool>(n,false);
            scanf("%s %s", s, s2);
            int id1 = mapa[s], id2 = mapa[s2];
            priority_queue<PII> Q;
            Q.push(PII(0,id1));
            dist[id1] = 0;
            while (!Q.empty()) {
                int u = Q.top().second; Q.pop();
                if (u == id2) break;
                if (tree[u]) continue;
                tree[u] = true;
                for (int i = 0; i < (int)adj[u].size(); i++) {
                    int v = adj[u][i].first, c = adj[u][i].second;
                    if (dist[v] > dist[u] + c)
                        Q.push(PII(-(dist[v] = dist[u] + c), v));
                }
            }
            printf("%d\n", dist[id2]);
        }
    }

    return 0;
}
