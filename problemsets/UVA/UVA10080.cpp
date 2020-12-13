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
#include <numeric>

using namespace std;

int N, M, S, V;

const int MAXV = 200;
int PAR[MAXV];
int MATCH;
vector<int> adj[MAXV];
int disc[MAXV];
int augment(int u, int c) {
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
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
    for (int i = 0; i < M+N; i++) disc[i] = PAR[i] = -1;
    for (int i = 0; i < M; i++) if (adj[i].size() && PAR[i]==-1) MATCH += augment(i, i);
    return MATCH;
}

double GX[200], GY[200],
       HX[200], HY[200];

int main() {

    while (scanf("%d %d %d %d", &M, &N, &S, &V) != EOF) {
        for (int i = 0; i < M; i++) scanf("%lf %lf", GX+i, GY+i);
        for (int i = 0; i < N; i++) scanf("%lf %lf", HX+i, HY+i);
        for (int i = 0; i < N+M; i++) adj[i].clear();
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) {
            double dx = GX[i]-HX[j],
                   dy = GY[i]-HY[j];
            if (dx*dx+dy*dy < S*V*S*V+1E-10) adj[i].push_back(M+j), adj[M+j].push_back(i);
        }
        int ret = M - bpm();
        printf("%d\n", ret);
    }

    return 0;
}
