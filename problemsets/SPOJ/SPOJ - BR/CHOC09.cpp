/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>


using namespace std;

int C[1010101], K[1010101];

int solve(int N, int M) {
    for (int i = 0; i <= N; i++) {
        if (C[i]==0) for (int j = 1; j <= M; j++) C[i+j]++, K[i+j] = j;
        else if (C[i]==1) C[i+K[i]]++, K[i+K[i]] = K[i];
    }
    return C[N];
}

int main() {


    int N, M;
    scanf("%d %d", &N, &M);
    if (M <= 4) { printf("%s\n", N%(M+1) ? "Paula" : "Carlos"); return 0; }
    solve(N,M);
    printf("%s\n", C[N] ? "Paula" : "Carlos");

    return 0;
}
