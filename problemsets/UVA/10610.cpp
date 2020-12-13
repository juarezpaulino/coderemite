/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

double X[1010], Y[1010];
int N;
vector<int> adj[1010];
int D[1010];
char S[101010];

int main() {

    int v, m;
    while (scanf("%d %d", &v, &m)) {
        if (!(v|m)) break;
        double M = m*60;
        double V = v;
        double x, y;
        scanf("%lf %lf ", X, Y);
        scanf("%lf %lf ", X+1, Y+1);
        N = 2;
        while (gets(S)) {
            if (*S==0) break;
            sscanf(S, "%lf %lf", X+N, Y+N);
            N++;
        }
        for (int i = 0; i < N; i++) adj[i].clear(), D[i] = -1;
        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) {
            double dx = X[i]-X[j];
            double dy = Y[i]-Y[j];
            double d = sqrt(dx*dx+dy*dy);
            if (M-d/V > -1E-10) adj[i].push_back(j), adj[j].push_back(i);
        }
        queue<int> q;
        q.push(0);
        D[0] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == 1) break;
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i];
                if (D[v]==-1) {
                    D[v] = D[u]+1;
                    q.push(v);
                }
            }
        }
        if (D[1]==-1) puts("No.");
        else printf("Yes, visiting %d other holes.\n", D[1]-1);
    }

    return 0;
}
