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

int E;
vector<int> adj[3000];
int D[3000];


int main() {

    scanf("%d", &E);
    for (int i = 0; i < E; i++) {
        int v, M;
        scanf("%d", &M);
        while (M--) { scanf("%d", &v); adj[i].push_back(v); }
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int s;
        scanf("%d", &s);
        if (adj[s].size() == 0) { puts("0"); continue; }
        for (int i = 0; i < E; i++) D[i] = -1;
        D[s] = 0;
        queue<int> q;
        q.push(s);
        int ret = 0, day;
        int c = 1;
        int k = 1;
        while (!q.empty()) {
            int d = 0;
            for (int i = 0; i < c; i++) {
                int u = q.front(); q.pop();
                for (int i = 0; i < adj[u].size(); i++) {
                    int v = adj[u][i];
                    if (D[v]==-1) {
                        d++;
                        D[v] = D[u]+1;
                        q.push(v);
                    }
                }
            }
            if (d > ret) ret = d, day = k;
            k++;
            c = d;
        }
        printf("%d %d\n", ret, day);
    }

    return 0;
}
