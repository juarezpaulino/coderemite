/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAXV = 200;

int P, k;
int PAR[MAXV];
int MATCH;
int X[MAXV], Y[MAXV];
char color[MAXV];
vector<int> adj[MAXV], dist[MAXV];
int disc[MAXV];
int D;
int augment(int u, int c) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (dist[u][i] > D) continue;
        if (disc[v] != c) {
            disc[v] = c;
            if (PAR[v]==-1 || augment(PAR[v], c))
                return (PAR[v]=u, PAR[u]=v, 1);
        }
    }
    return 0;
}
int bpm() {
    MATCH = 0;
    for (int i = 0; i < P; i++) disc[i] = PAR[i] = -1;
    for (int i = 0; i < P; i++) if (adj[i].size() && PAR[i]==-1) MATCH += augment(i, i);
    return MATCH;
}


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        char S[1010];
        scanf("%d %d", &P, &k);
        int nblue = 0, nred = 0;
        for (int i = 0; i < P; i++) {
            scanf("%d %d %s", X+i, Y+i, S);
            if (!strcmp(S, "blue")) color[i] = 0, nblue++;
            else color[i] = 1, nred++;
            adj[i].clear();
            dist[i].clear();
        }
        for (int i = 0; i < P; i++) for (int j = i+1; j < P; j++) if (color[i]!=color[j]) {
            int dx = X[i]-X[j];
            int dy = Y[i]-Y[j];
            adj[i].push_back(j); dist[i].push_back(dx*dx+dy*dy);
            adj[j].push_back(i); dist[j].push_back(dx*dx+dy*dy);
        }
        if (min(nblue,nred) < k) { puts("Impossible"); continue; }
        int a = 1, b = 4000;
        while (a < b) {
            int m = (a+b)/2;
            D = m*m;
            if (bpm()>=k) {
                b = m;
            } else {
                a = m+1;
            }
        }
        printf("%d\n", b);

    }

    return 0;
}
