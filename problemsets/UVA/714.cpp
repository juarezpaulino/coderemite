/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>

using namespace std;

int main() {

    int T;
    int M, K, P[505], RET[505];
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &M, &K);
        long long mini = 1, maxi = 0;
        for (int i = 0; i < M; i++) scanf("%d", P+i), maxi += P[i];
        while (mini < maxi) {
            long long m = mini + (maxi-mini) / 2;
            int i = 0, k = 0;
            while (k < K && i < M) {
                int v = 0;
                while (i < M && v+P[i] <= m) v += P[i++];
                k++;
            }
            if (i < M) mini = m+1;
            else maxi = m;
        }
        memset(RET, 0, sizeof(RET));
        int i = M-1, k = 0;
        while (k < K && i > K-k-1) {
            int v = 0;
            while (i >= K-k-1 && v + P[i] <= maxi) v += P[i--];
            if (i > 0) RET[i+1] = 1;
            k++;
        }
        while (i > 0) RET[i--] = 1;
        for (int i = 0; i < M; i++) {
            if (RET[i]) printf(" /");
            if (i == 0) printf("%d", P[i]);
            else printf(" %d", P[i]);
        }
        putchar('\n');
    }

    return 0;
}
