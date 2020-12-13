/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int V, E;
char dir[505];
int edge[505][2];
int deg[101], need[101];

vector<int> adj[101];
int par[505], disc[101], id = 1;

int augment(int u) {
    if (disc[u]==id) return 0;
    disc[u] = id;
    for (int i = 0; i < adj[u].size(); i++) {
        int e = adj[u][i];
        if (par[e]==-1 || augment(par[e]))
            return (par[e] = u, 1);
    }
    return 0;
}

inline int bpm() {
    id++;
    for (int i = 1; i <= V; i++)
        while (need[i]--) {
            if (!augment(i)) return 0;
            id++;
        }
    return 1;
}

vector<int> ret;

void euler(int u) {
    while (adj[u].size() > 0) {
        int v = adj[u].back();
        adj[u].pop_back();
        euler(v);
    }
    ret.push_back(u);
}


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &V, &E);
        for (int i = 1; i <= V; i++) deg[i] = 0, adj[i].clear();

        for (int i = 0; i < E; i++) {
            int u, v; char c;
            scanf("%d %d %c", &u, &v, &c);
            edge[i][0] = u; edge[i][1] = v;
            deg[u]++; deg[v]++;
            dir[i] = (c=='D');
        }

        bool ok = 1;
        for (int i = 1; i <= V; i++)
            if (deg[i]%2!=0) ok = 0;
            else need[i] = deg[i]/2;
        if (!ok) { puts("No euler circuit exist"); if (T) puts(""); continue; }

        for (int i = 0; i < E; i++) {
            par[i] = -1;
            if (dir[i]) need[edge[i][1]]--, par[i] = edge[i][1];
            else    adj[edge[i][0]].push_back(i),
                    adj[edge[i][1]].push_back(i);
        }

        ok = bpm();
        if (!ok) { puts("No euler circuit exist"); if (T) puts(""); continue; }

        for (int i = 1; i <= V; i++) adj[i].clear();
        for (int i = 0; i < E; i++) {
            if (dir[i] || par[i]==edge[i][1]) adj[edge[i][1]].push_back(edge[i][0]);
            else adj[edge[i][0]].push_back(edge[i][1]);
        }

        ret.clear();
        euler(1);
        if (ret.size() != E+1) puts("No euler circuit exist");
        else {
            printf("1");
            for (int i = 1; i < ret.size(); i++) printf(" %d", ret[i]);
            putchar('\n');
        }

        if (T) putchar('\n');
    }

    return 0;
}
