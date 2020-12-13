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

using namespace std;

int main() {

    int N;
    int P[10];
    char T[256], V[10];
    int id = 1;
    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) {
            int x;
            scanf(" x%d ", &x);
            P[i] = x-1;
        }
        scanf("%s", T);
        int K;
        scanf("%d", &K);
        printf("S-Tree #%d:\n", id++);
        for (int i = 0; i < K; i++) {
            scanf("%s", V);
            int ret = 1;
            for (int i = 0; i < N; i++)
                if (V[P[i]]=='1') ret = ret*2 + 1;
                else ret = ret*2;
            ret -= 1<<N;
            putchar(T[ret]);
        }
        putchar('\n');
        putchar('\n');
    }

    return 0;
}
