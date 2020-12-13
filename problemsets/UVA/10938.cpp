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

using namespace std;

const int MAXV = 5050;
const int LOGMAXV = 13;

int N;
vector<int> adj[MAXV];

namespace LCA {
    int L[MAXV], T[MAXV], P[MAXV][LOGMAXV];
    void dfs_tree(int u) {
        for (int i = 0, v; i < adj[u].size(); i++) {
            v = adj[u][i];
            if (v != T[u]) L[v] = L[u]+1, T[v] = u, dfs_tree(v);
        }
    }
    void INIT() {
        for (int i = 0; i < N; i++) T[i] = L[i] = -1;
        for (int i = 0; i < N; i++)
            if (T[i]==-1) L[i] = 0, dfs_tree(i);
        for (int i = 0; i < N; i++) for (int j = 0; 1<<j < N; j++) P[i][j] = -1;
        for (int i = 0; i < N; i++) P[i][0] = T[i];
        for (int j = 1; 1<<j < N; j++) for (int i = 0; i < N; i++)
            if (P[i][j-1] != -1) P[i][j] = P[P[i][j-1]][j-1];
    }
    int QUERY(int x, int y) {
        if (L[x] < L[y]) swap(x,y);
        int log; for (log = 1; 1<<log <= L[x]; log++); log--;
        for (int i = log; i >= 0; i--)
            if (L[x] - (1<<i) >= L[y]) x = P[x][i];
        if (x == y) return x;
        for (int i = log; i >= 0; i--)
            if (P[x][i] != -1 && P[x][i] != P[y][i])
                x = P[x][i], y = P[y][i];
        return T[x];
    }
    pair<int,int> CENTER(int x, int y) {
        if (L[x] < L[y]) swap(x,y);
        int d = L[x]+L[y]-2*L[QUERY(x,y)];
        int k = d / 2;
        while (k) {
            int log; for (log = 1; 1<<log <= k; log++); log--;
            x = P[x][log];
            k -= 1<<log;
        }
        pair<int,int> ret = (d%2) ? make_pair(x,T[x]) : make_pair(x,x);
        if (ret.first > ret.second) swap(ret.first,ret.second);
        return ret;
    }
};


int main() {

    while (scanf("%d", &N) && N) {
        for (int i = 0; i < N; i++) adj[i].clear();
        for (int i = 0; i < N-1; i++) {
            int u, v;
            scanf("%d %d", &u, &v); u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        LCA::INIT();
        int q; scanf("%d", &q);
        while (q--) {
            int u, v;
            scanf("%d %d", &u, &v); u--; v--;
            pair<int,int> ret = LCA::CENTER(u,v);
            if (ret.first != ret.second)
                printf("The fleas jump forever between %d and %d.\n", ret.first+1, ret.second+1);
            else
                printf("The fleas meet at %d.\n", ret.first+1);
        }
    }

    return 0;
}
