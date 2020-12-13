/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int N, T;
int V[2][3];

int main() {

    while (1) {
        scanf("%d", &N);
        if (!N) break;

        scanf("%d %d %d", &V[0][0], &V[0][1], &V[0][2]);
        V[0][0] = V[0][1];
        V[0][2] = min(V[0][1], V[0][1]+V[0][2]);
        int k = 1;
        for (int i = 1; i < N; i++) {
            int l = k^1;
            int A, B, C;
            scanf("%d %d %d", &A, &B, &C);

            V[k][0] = A + min(V[l][0], V[l][1]);

            V[k][1] = B + min(V[k][0], min(V[l][0], min(V[l][1], V[l][2])));

            V[k][2] = C + min(V[k][1], min(V[l][1], V[l][2]));

            k = l;
        }

        printf("%d. %d\n", ++T, V[k^1][1]);
    }

    return 0;
}
