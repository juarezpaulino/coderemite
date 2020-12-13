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

    int T, N, K;
    int H[20100];

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &K);
        for (int i = 0; i < N; i++) scanf("%d", H+i);
        sort(H, H+N);
        int mini = 0x3F3F3F3F;
        for (int i = K-1; i < N; i++)
            mini = min(mini, H[i]-H[i-K+1]);
        printf("%d\n", mini);
    }

    return 0;
}
