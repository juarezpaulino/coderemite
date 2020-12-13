/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

double X[110], Y[110], R[110];
int vis[110], V;
vector<int> adj[110];

void dfs(int u) {
    V++; vis[u] = 1;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!vis[v]) dfs(v);
    }
}

int main() {

    int N;
    while (scanf("%d", &N) != EOF) {
        if (N == -1) break;
        for (int i = 0; i < N; i++) scanf("%lf %lf %lf", X+i, Y+i, R+i), adj[i].clear(), vis[i] = 0;
        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) {
            double dx = X[i]-X[j], dy = Y[i]-Y[j];
            double d = dx*dx+dy*dy;
            double dR = R[i]+R[j]; dR *= dR;
            double dr = fabs(R[i]-R[j]); dr *= dr;
            if (d < dR-1E-10 && d > dr-1E-10) adj[i].push_back(j), adj[j].push_back(i);
        }
        int ret = 0;
        for (int i = 0; i < N; i++) if (!vis[i]) {
            V = 0; dfs(i); if (V > ret) ret = V;
        }
        printf("The largest component contains %d ring%s.\n", ret, ret != 1 ? "s" : "");
    }

    return 0;
}
