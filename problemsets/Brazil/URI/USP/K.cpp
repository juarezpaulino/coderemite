/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int id = 1;
int U[101010];
int S[101010];
int ret[101010];

int main() {

    int K, N;
    while (scanf("%d %d", &K, &N) != EOF) {
        for (int i = 0; i < K; i++) scanf("%d", S+i);
        int k = 0;
        for (int i = 0; i < K; i++) {
            if (U[S[i]] == id) continue;
            ret[k++] = S[i];
            U[S[i]] = id;
        }
        printf("%d", ret[0]);
        for (int i = 1; i < N; i++) printf(" %d", ret[i]);
        putchar('\n');
        id++;
    }

    return 0;
}
