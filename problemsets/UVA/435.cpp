/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int ret[20], V[20];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int P;
        scanf("%d", &P);
        int t = 0;
        for (int i = 0; i < P; i++) scanf("%d", V+i), ret[i] = 0, t += V[i];
        t /= 2;
        for (int i = 0; i < (1<<P); i++) {
            int v = 0;
            for (int j = 0; j < P; j++) if (i&(1<<j)) v += V[j];
            if (v > t) for (int j = 0; j < P; j++) if ((i&(1<<j)) && v-V[j] <= t) ret[j]++;
        }
        for (int i = 0; i < P; i++) printf("party %d has power index %d\n", i+1, ret[i]);
        putchar('\n');
    }

    return 0;
}
