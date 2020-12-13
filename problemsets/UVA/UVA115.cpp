/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;


#define SI(A) (int)((A).size())

const int MAXV = 500;
const int LOGMAXV = 10;

int N;
vector<int> adj[MAXV];

namespace LCA {
    int L[MAXV], T[MAXV], P[MAXV][LOGMAXV];
    void dfs_tree(int u) {
        for (int i = 0, v; i < SI(adj[u]); i++) {
            v = adj[u][i];
            if (v != T[u]) T[v] = u, dfs_tree(v);
        }
    }
    void dfs_level(int u) {
        for (int i = 0, v; i < SI(adj[u]); i++) {
            v = adj[u][i];
            if (L[v]==-1) L[v] = L[u]+1, dfs_level(v);
        }
    }
    void INIT() {
        for (int i = 0; i < N; i++) T[i] = L[i] = -1;
        for (int i = 0; i < N; i++)
            if (T[i]==-1) dfs_tree(i);
        for (int i = 0; i < N; i++)
            if (T[i]==-1) L[i] = 0, dfs_level(i);
        for (int i = 0; i < N; i++) for (int j = 0; 1<<j < N; j++) P[i][j] = -1;
        for (int i = 0; i < N; i++) P[i][0] = T[i];
        for (int j = 1; 1<<j < N; j++) for (int i = 0; i < N; i++)
            if (P[i][j-1] != -1) P[i][j] = P[P[i][j-1]][j-1];
    }
    int QUERY(int x, int y) {
        if (L[x] < L[y]) swap(x,y);
        int log;
        for (log = 1; 1<<log <= L[x]; log++);
        log--;
        for (int i = log; i >= 0; i--)
            if (L[x] - (1<<i) >= L[y]) x = P[x][i];
        if (x == y) return x;
        for (int i = log; i >= 0; i--)
            if (P[x][i] != -1 && P[x][i] != P[y][i])
                x = P[x][i], y = P[y][i];
        return T[x];
    }
};


int main() {

//    freopen("UVA.in", "r", stdin);

    map<string, int> MAPA;
    N = 0;
    while(1) {
        string P, C;
        cin >> C >> P;
        if (C == "no.child") break;
        int x, y;
        x = (MAPA.count(P)) ? MAPA[P] : MAPA[P] = N++;
        y = (MAPA.count(C)) ? MAPA[C] : MAPA[C] = N++;
        adj[x].push_back(y);
    }

    LCA::INIT();
    string X, Y;
    while(cin >> X >> Y) {
        if (!MAPA.count(X) || !MAPA.count(Y)) {
            puts("no relation");
            continue;
        }
        int x = MAPA[X], y = MAPA[Y];
        int p = LCA::QUERY(x,y);
        if (x == y) printf("%d", 1/0);
        else if (p == -1) puts("no relation");
        else if (p == x) {
            int k = LCA::L[y] - LCA::L[x], i;
            for (i = 0; i < k-2; i++) printf("great ");
            if (i == k-2) printf("grand ");
            puts("parent");
        }
        else if (p == y) {
            int k = LCA::L[x] - LCA::L[y], i;
            for (i = 0; i < k-2; i++) printf("great ");
            if (i == k-2) printf("grand ");
            puts("child");
        }
        else if (LCA::T[x] == p && LCA::T[y] == p) puts("sibling");
        else {
            int m = LCA::L[x] - LCA::L[p] - 1,
                n = LCA::L[y] - LCA::L[p] - 1,
                r = abs(m-n);
            printf("%d cousin", min(m, n));
            if (r) printf(" removed %d", r);
            putchar('\n');
        }
    }

    return 0;
}
