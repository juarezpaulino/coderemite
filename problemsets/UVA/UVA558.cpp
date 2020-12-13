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

const int INF = 0x3F3F3F3F;

int N;
vector<int> adj[1000], custo[1000];
int dist[1000];

bool bellman_ford(int s) {
    bool negcy = false;
    for (int i = 0; i < N; i++) dist[i] = INF;
    dist[s] = 0;
    for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < adj[i].size(); j++)
        if (dist[adj[i][j]] > dist[i] + custo[i][j]) {
            dist[adj[i][j]] = dist[i] + custo[i][j];
            if (k == N-1) return dist[adj[i][j]] = -INF, negcy = true, false;
        }
    return !negcy;
}


int main() {

    int T, M;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        int u, v, c;
        for (int i = 0; i < M; i++) scanf("%d %d %d", &u, &v, &c), adj[u].push_back(v), custo[u].push_back(c);
        if (!bellman_ford(0)) puts("possible");
        else puts("not possible");
        for (int i = 0; i < N; i++) adj[i].clear(), custo[i].clear();
    }

    return 0;
}
