/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;


int main() {

    int M, N, K;
    int R[110], F[110];
    double V[10101];
    while (scanf("%d %d", &M, &N)) {
        if (!M|!N) break;
        for (int i = 0; i < M; i++) scanf("%d", R+i);
        for (int i = 0; i < N; i++) scanf("%d", F+i);
        K = 0;
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) V[K++] = F[j]/(double)R[i];
        sort(V, V+K);
        double ret = -1E10;
        for (int i = 1; i < K; i++) ret = max(ret, V[i]/V[i-1]);
        printf("%.2lf\n", ret);
    }

    return 0;
}
