/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

typedef long long i64;

i64 horner(int C[], int N, int x) {
    i64 ret = C[N];
    for (int i = N-1; i >= 0; i--) ret = ret*x + C[i];
    return ret;
}

int C[1000];
int N, x, K;

int main() {

    int id = 1;
    while (1) {
        scanf("%d", &N);
        if (N == -1) break;
        for (int i = N; i >= 0; i--) scanf("%d", C+i);
        scanf("%d", &K);
        printf("Case %d:\n", id);
        while (K--) {
            scanf("%d", &x);
            printf("%lld\n", horner(C, N, x));
        }
        id++;
    }

    return 0;
}
