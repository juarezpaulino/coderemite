/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int N, M[101][101];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &M[i][j]);
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        int x;
        scanf("%d", &x);
        M[i][j] += x;
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        printf("%d", M[i][j]);
        if (j < N-1) putchar(' ');
        else putchar('\n');
    }

    return 0;
}
