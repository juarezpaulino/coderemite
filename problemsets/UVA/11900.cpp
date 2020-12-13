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
        int N, P, Q;
        scanf("%d %d %d", &N, &P, &Q);
        int ret = 0, v = 0;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            if (v + x <= Q) ret++, v += x;
        }
        if (P < ret) ret = P;
        printf("Case %d: %d\n", t, ret);
    }

    return 0;
}
