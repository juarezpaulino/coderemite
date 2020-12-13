/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <stack>

using namespace std;

int main() {

    char A[101], B[101];
    map<string, int> M;
    vector<string> D;
    vector<vector<int> > adj;
    int N, u, v, x, y;
    bool nl = 0;
    while (scanf("%d", &N) != EOF) {
        M.clear();
        adj.clear();
        D.clear();
        for (int i = 0; i < N; i++) {
            scanf("%s %s", A, B);
            if (!M.count(A)) u = M.size(), M[A] = u, D.push_back(A), adj.push_back(vector<int>());
            else u = M[A];
            if (!M.count(B)) v = M.size(), M[B] = v, D.push_back(B), adj.push_back(vector<int>());
            else v = M[B];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (nl) putchar('\n');
        nl = 1;
        scanf("%s %s", A, B);
        if (!M.count(A)) { puts("No route"); continue; }
        if (!M.count(B)) { puts("No route"); continue; }
        queue<int> q;
        vector<int> P(adj.size(), -1), V(adj.size(), 0);
        u = M[A], v = M[B];
        q.push(u);
        V[u] = 1;
        while (!q.empty()) {
            x = q.front(); q.pop();
            for (int i = 0; i < adj[x].size(); i++) {
                y = adj[x][i];
                if (V[y]) continue;
                q.push(y); V[y] = 1; P[y] = x;
            }
        }
        if (!V[v]) { puts("No route"); continue; }
        stack<pair<int,int> > S;
        while (P[v] != -1) {
            S.push(make_pair(P[v], v));
            v = P[v];
        }
        while (!S.empty()) {
            pair<int,int> p = S.top(); S.pop();
            printf("%s %s\n", D[p.first].c_str(), D[p.second].c_str());
        }
    }

    return 0;
}
