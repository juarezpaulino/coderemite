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

map<int, int> M;
vector< vector<int> > adj;
vector<int> IN, V;
int N;
bool ok;

void DFS(int u) {
    V[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (V[v]) { ok = false; return; }
        DFS(v);
    }
}

int main() {

    int T = 1;
    while (1) {
        adj.clear();
        V.clear();
        IN.clear();
        M.clear();
        N = 0;
        while (1) {
            int x, y, u, v;
            scanf("%d %d", &x, &y);
            if (x < 0 || y < 0) return 0;
            if (x==0 && y==0) break;
            if (!M.count(x)) { u = M.size(); M[x] = u; adj.push_back(vector<int>()); IN.push_back(0); V.push_back(0); N++; }
            else u = M[x];
            if (!M.count(y)) { v = M.size(); M[y] = v; adj.push_back(vector<int>()); IN.push_back(0); V.push_back(0); N++; }
            else v = M[y];
            adj[u].push_back(v);
            IN[v]++;
        }
        if (N == 0) { printf("Case %d is a tree.\n", T++); continue; }
        ok = true;
        int u = -1;
        for (int i = 0; i < N; i++) if (IN[i]==0) {
            if (u != -1) ok = false;
            u = i;
        }
        if (u == -1) ok = false;
        if (!ok) { printf("Case %d is not a tree.\n", T++); continue; }
        DFS(u);
        for (int i = 0; i < N; i++) if (i != u && !V[i]) { ok = false; break; }
        if (!ok) { printf("Case %d is not a tree.\n", T++); continue; }
        printf("Case %d is a tree.\n", T++);
    }

    return 0;
}
