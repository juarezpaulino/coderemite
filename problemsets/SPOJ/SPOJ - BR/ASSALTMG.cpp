/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int T, M, D;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &M, &D);
        int V[20] = {0};
        for (int i = 0; i < D; i++) {
            int n, x;
            scanf("%d", &n);
            while (n--) scanf("%d", &x), V[i]|=(1<<x);
        }
        int ret = -1;
        for (int i = 0; i < (1<<D); i++) {
            int v = 0;
            for (int j = 0; j < D; j++) if (i & (1<<j)) v |= V[j];
            if (__builtin_popcount(v) >= M) {
                if (ret == -1 || ret > __builtin_popcount(i)) ret = __builtin_popcount(i);
            }
        }
        if (ret == -1) puts("Desastre!");
        else printf("%d\n", ret);
    }

    return 0;
}
