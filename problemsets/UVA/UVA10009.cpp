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

vector< vector<int> > adj;
map<string, int> MAPA;
vector<char> C;
int N, M, Q;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        adj.clear(); N = 0; MAPA.clear(); C.clear();
        scanf("%d %d", &M, &Q);
        for (int i = 0; i < M; i++) {
            char S[100], T[100];
            scanf("%s %s", S, T);
            int u, v;
            if (!MAPA.count(S)) { u = MAPA.size(); MAPA[S] = u; C.push_back(*S); adj.push_back(vector<int>()); N++; }
            else u = MAPA[S];
            if (!MAPA.count(T)) { v = MAPA.size(); MAPA[T] = v; C.push_back(*T); adj.push_back(vector<int>()); N++; }
            else v = MAPA[T];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < Q; i++) {
            char S[100], T[100];
            scanf("%s %s", S, T);
            int u = MAPA[S], v = MAPA[T];
            queue<int> q;
            vector<bool> V(N, false);
            vector<int> P(N, -1);
            V[u] = 1;
            q.push(u);
            while (!q.empty()) {
                u = q.front(); q.pop();
                if (u == v) break;
                for (int i = 0; i < adj[u].size(); i++) {
                    int y = adj[u][i];
                    if (!V[y]) { V[y] = 1; P[y] = u; q.push(y); }
                }
            }
            string ret = string(1, C[v]);
            while (P[v] != -1) {
                v = P[v];
                ret = string(1, C[v]) + ret;
            }
            printf("%s\n", ret.c_str());
        }
        if (T) putchar('\n');
    }

    return 0;
}
