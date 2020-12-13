/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int N, A[50];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", A+i);
    for (int i = 0; i < N; i++) {
        int c = (i > 0) ? A[i-1] : 0;
        c += A[i];
        if (i < N-1) c += A[i+1];
        printf("%d\n", c);
    }

    return 0;
}
