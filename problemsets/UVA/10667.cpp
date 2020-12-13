/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int M[110][110];

int main() {

    int P;
    scanf("%d", &P);
    while (P--) {
        int S, B;
        scanf("%d", &S);
        int r1, r2, c1, c2;
        for (int i = 0; i < S; i++) for (int j = 0; j < S; j++) M[i][j] = 1;
        scanf("%d", &B);
        for (int k = 0; k < B; k++) {
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            r1--; r2--; c1--; c2--;
            for (int i = r1; i <= r2; i++) for (int j = c1; j <= c2; j++) M[i][j] = 0;
        }
        int ret = 0;
        for (int k = 0; k < S; k++) {
            int v[110];
            for (int j = 0; j < S; j++) v[j] = 1;
            bool ok = 1;
            for (int i = k; ok && i < S; i++) {
                ok = 0;
                int l = -1;
                for (int j = 0; j < S; j++) {
                    if (M[i][j] && v[j]) ret = max(ret, (i-k+1)*(j-l)), ok = 1;
                    else v[j] = 0, l = j;
                }
            }
        }
        printf("%d\n", ret);
    }

    return 0;
}
