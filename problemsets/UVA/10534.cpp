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

    int N;
    int A[101010];
    int L[101010], R[101010];
    int P[101010], p;
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) scanf("%d", A+i);
        p = 1; P[0] = A[0]; L[0] = 1;
        for (int i = 1; i < N; i++) {
            L[i] = lower_bound(P, P+p, A[i]) - P + 1;
            P[L[i]-1] = A[i];
            p = max(p, L[i]);
        }
        p = 1; P[0] = A[N-1]; R[N-1] = 1;
        for (int i = N-2; i >= 0; i--) {
            R[i] = lower_bound(P, P+p, A[i]) - P + 1;
            P[R[i]-1] = A[i];
            p = max(p, R[i]);
        }
        int ret = -1;
        for (int i = 0; i < N; i++) ret = max(ret, min(L[i], R[i])*2 -1);
        printf("%d\n", ret);
    }

    return 0;
}
