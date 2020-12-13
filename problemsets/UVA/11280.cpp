/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

vector<int> adj[110], cost[110];

int main() {

    char A[10101], B[10101];
    int N, M;
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        if (t > 1) putchar('\n');
        printf("Scenario #%d\n", t);
        scanf("%d", &N);
        map<string,int> mapa;
        for (int i = 0; i < N; i++) { scanf("%s", A); mapa[A] = i; adj[i].clear(); cost[i].clear(); }
        scanf("%d", &M);
        while (M--) {
            int c;
            scanf("%s %s %d", A, B, &c);
            int u = mapa[A], v = mapa[B];
            adj[u].push_back(v); cost[u].push_back(c);
        }
        vector<vector<int> > D(N, vector<int>(N, 1<<30));
        priority_queue<pair<int,pii> > q;
        q.push(make_pair(-(D[0][0] = 0),pii(-0,0)));
        while (!q.empty()) {
            int u = q.top().second.second,
                k = -q.top().second.first,
                d = -q.top().first;
            q.pop();
            if (d > D[u][k]) continue;
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i], c = cost[u][i];
                if (D[v][k+1] > d+c)
                    q.push(make_pair(-(D[v][k+1] = d+c),pii(-(k+1),v)));
            }
        }
        for (int i = 1; i < N; i++)
            D[N-1][i] = min(D[N-1][i], D[N-1][i-1]);
        int Q;
        scanf("%d", &Q);
        while (Q--) {
            int p;
            scanf("%d", &p);
            p = max(0,min(p, N-2));
            if (D[N-1][p+1] == 1<<30) printf("No satisfactory flights\n");
            else printf("Total cost of flight(s) is $%d\n", D[N-1][p+1]);
        }
    }

    return 0;
}
