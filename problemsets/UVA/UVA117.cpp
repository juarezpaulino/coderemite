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

vector<int> adj[30], cost[30];
int dist[30], vis[30];

char S[1000];

const int INF = 0x3F3F3F3F;

int main() {

    while (1) {
        for (int i = 0; i < 30; i++) adj[i].clear(), cost[i].clear();
        int ret = 0;
        while (1) {
            if (!gets(S)) return 0;
            if (!strcmp(S,"deadend")) break;
            int N = strlen(S);
            adj[S[0]-'a'].push_back(S[N-1]-'a');
            adj[S[N-1]-'a'].push_back(S[0]-'a');
            cost[S[0]-'a'].push_back(N);
            cost[S[N-1]-'a'].push_back(N);
            ret += N;
        }
        int s = 0;
        for (int i = 0; i < 30; i++) {
            if (adj[i].size()%2) s = i;
            dist[i] = INF;
            vis[i] = 0;
        }
        priority_queue<pair<int, int> > Q;
        Q.push(make_pair(-(dist[s] = 0), s));
        int u = 0, v, c;
        while (!Q.empty()) {
            u = Q.top().second; Q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            if (u != s && adj[u].size()%2) break;
            for (int i = 0; i < adj[u].size(); i++) {
                v = adj[u][i]; c = dist[u] + cost[u][i];
                if (c < dist[v])
                    Q.push(make_pair(-(dist[v] = c), v));
            }
        }
        ret += dist[u];
        printf("%d\n", ret);
    }

    return 0;
}
