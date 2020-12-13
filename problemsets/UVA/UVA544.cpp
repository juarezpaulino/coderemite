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

const int INF = 0x3F3F3F3F;

int N, M;
map<string, int> MAPA;
int adj[200][200];
char A[50], B[50];

int main() {

    int T = 1;
    while (scanf("%d %d", &N, &M)) {
        MAPA.clear();
        if (!(N|M)) break;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) adj[i][j] = (i==j) ? INF : 0;
        for (int i = 0; i < M; i++) {
            int c;
            scanf("%s %s %d", A, B, &c);
            int u, v;
            if (!MAPA.count(A)) { u = MAPA.size(); MAPA[A] = u; }
            else u = MAPA[A];
            if (!MAPA.count(B)) { v = MAPA.size(); MAPA[B] = v; }
            else v = MAPA[B];
            adj[u][v] = adj[v][u] = c;
        }
        for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            int d = min(adj[i][k],adj[k][j]);
            if (d > adj[i][j]) adj[i][j] = d;
        }
        scanf("%s %s", A, B);
        int u = MAPA[A], v = MAPA[B];
        printf("Scenario #%d\n", T++);
        printf("%d tons\n\n", adj[u][v]);
    }

    return 0;
}
