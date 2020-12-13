/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int V[100];
int S[15];

int josephus(int N, int K) {
    int p = -1;
    int M = N;
    for (int i = 0; i < N; i++) V[i] = i+1;
    do {
        p = (p+K)%M;
        if (V[p] <= N/2) return 0;
        copy(V+p+1, V+M, V+p);
        M--;
        p = (p+M-1)%M;
    } while (M > N/2);
    return 1;
}


int main() {

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        if (S[N]) printf("%d\n", S[N]);
        else {
            for (int M = N+1; ; M++) {
                if (josephus(N*2,M)) { S[N] = M; break; }
            }
            printf("%d\n", S[N]);
        }
    }

    return 0;
}
