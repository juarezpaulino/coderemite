/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int N, B, H, W;
    while (scanf("%d %d %d %d", &N, &B, &H, &W) != EOF) {
        int ret = -1;
        for (int i = 0; i < H; i++) {
            int p, x;
            scanf("%d", &p);
            for (int j = 0; j < W; j++) {
                scanf("%d", &x);
                if (x >= N && N*p <= B) ret = (ret == -1) ? N*p : min(ret, N*p);
            }
        }
        if (ret == -1) puts("stay home");
        else printf("%d\n", ret);
    }

    return 0;
}
