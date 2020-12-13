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
    while (T--) {
        char S[10101], c;
        int N, v;
        int D[257] = {0};
        scanf("%d\n", &N);
        for (int i = 0; i < N; i++) {
            scanf("%c %d\n", &c, &v);
            D[c+128] = v;
        }
        int M;
        scanf("%d\n", &M);
        int ret = 0;
        while (M--) {
            gets(S);
            for (int i = 0; S[i]; i++) ret += D[S[i]+128];
        }
        printf("%d.%02d$\n", ret/100, ret%100);
    }

    return 0;
}
