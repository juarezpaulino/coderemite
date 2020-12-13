/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

vector<int> adj[100];
int DEG[100];
int RET[100];

int main() {

    int M, N;
    while (scanf("%d %d", &N, &M)) {
        if (!(M|N)) break;
        for (int i = 0; i < N; i++) adj[i].clear(), DEG[i] = 0;
        while (M--) {
            int u, v;
            scanf("%d %d", &u, &v);
            v--; u--;
            adj[u].push_back(v);
            DEG[v]++;
        }
        queue<int> Q;
        for (int i = 0; i < N; i++) if (DEG[i]==0) Q.push(i);
        int k = 0;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            RET[k++] = u;
            for (int i = 0; i < adj[u].size(); i++) {
                DEG[adj[u][i]]--;
                if (DEG[adj[u][i]]==0) Q.push(adj[u][i]);
            }
        }
        printf("%d", RET[0]+1);
        for (int i = 1; i < N; i++) printf(" %d", RET[i]+1);
        putchar('\n');
    }

    return 0;
}
