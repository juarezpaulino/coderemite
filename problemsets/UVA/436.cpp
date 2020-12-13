/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int N, M, id = 1;
    double G[30][30];
    while (scanf("%d", &N) != EOF) {
        if (!N) break;
        char S[1010], T[1010];
        map<string, int> MAPA;
        for (int i = 0; i < N; i++) {
            scanf("%s", S), MAPA[S] = i;
            for (int j = 0; j < N; j++) G[i][j] = (i==j) ? 1.0 : 0.;
        }
        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
            double x;
            scanf("%s %lf %s", S, &x, T);
            int s = MAPA[S], t = MAPA[T];
            G[s][t] = max(G[s][t], x);
        }
        for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            double d = G[i][k] * G[k][j];
            if (d > G[i][j]) G[i][j] = d;
        }
        bool ok = 0;
        for (int i = 0; !ok && i < N; i++) if (fabs(G[i][i]-1.) > 1E-10) ok = 1;
        if (ok) printf("Case %d: Yes\n", id++);
        else printf("Case %d: No\n", id++);
    }

    return 0;
}
