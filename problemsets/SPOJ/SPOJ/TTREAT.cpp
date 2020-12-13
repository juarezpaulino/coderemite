/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int N, M;
int ST[10101], END[10101];


int main() {

    while (1) {
        scanf("%d %d", &N, &M);
        if (!N && !M) break;
        for (int i = 0; i < N; i++) scanf("%*d %*d %d %d", ST+i, END+i);
        for (int k = 0; k < M; k++) {
            int b, e;
            scanf("%d %d", &b, &e);
            e = b+e;
            int ret = 0;
            for (int i = 0; i < N; i++) {
                if (END[i]<=0) continue;
                int b2 = ST[i], e2 = b2 + END[i];
                if (b2 < e && e2 > b) ret++;
            }
            printf("%d\n", ret);
        }
    }

    return 0;
}
