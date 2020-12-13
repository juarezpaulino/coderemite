/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int N, M[110][110];

int main() {

    scanf("%d", &N);
    int ret = 0;
    while (N--) {
        int xi, yi, xf, yf;
        scanf("%d %d %d %d", &xi, &xf, &yi, &yf);
        for (int i = xi; i < xf; i++) for (int j = yi; j < yf; j++) if (!M[i][j]) {
            M[i][j] = 1;
            ret++;
        }
    }
    printf("%d\n", ret);


    return 0;
}
