/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int N, M;
    scanf("%d %d", &N, &M);
    int p = -1, ret = -1;
    for (int i = 0; i < N; i++) {
        int c = 0, x;
        for (int j = 0; j < M; j++) scanf("%d", &x), c += x;
        if (p == -1 || c < ret) ret = c, p = i;
    }
    printf("%d\n", p+1);

    return 0;
}
