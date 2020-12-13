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
#include <cstring>
#include <string>

using namespace std;

int main() {

    int adj[50][50];
    int M, N, P, T;
    scanf("%d", &T);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    for (int t = 1; t <= T; t++) {
        printf("DATA SET  %d\n\n", t);
        scanf("%d %d %d", &M, &N, &P);
        map<string, int> MAPA;

        char S[1010], T[1010];
        int c, s, t;
        for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) adj[i][j] = (i==j) ? 0 : 0x3F3F3F3F;
        for (int i = 0; i < M; i++) scanf("%s", S), MAPA[S] = i;
        for (int i = 0; i < N; i++) {
            scanf("%s %s", S, T);
            s = MAPA[S], t = MAPA[T];
            if (s != t) adj[s][t] = adj[t][s] = 1;
        }
        for (int k = 0; k < M; k++) for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) {
            int d = adj[i][k]+adj[k][j];
            if (d < adj[i][j]) adj[i][j] = d;
        }
        for (int i = 0; i < P; i++) {
            scanf("%d %s %s", &c, S, T);
            s = MAPA[S]; t = MAPA[T];
            if (adj[s][t] >= 0x3F3F3F3F) puts("NO SHIPMENT POSSIBLE");
            else printf("$%d\n", adj[s][t]*100*c);
        }

        putchar('\n');
    }
    printf("END OF OUTPUT\n");

    return 0;
}
