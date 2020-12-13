/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, x;
        scanf("%d", &N);
        for (int i = 0; i < N/2; i++) scanf("%d", &x);
        scanf("%d", &x); printf("Case %d: %d\n", t, x);
        for (int i = N/2+1; i < N; i++) scanf("%d", &x);
    }

    return 0;
}
