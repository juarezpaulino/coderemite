/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int L[1010];
int N;

int main() {

    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 0; i <= N; i++) L[i] = 0;
        L[0] = 1<<30;
        int ret = 0;
        for (int i = 1; i <= N; i++) {
            int w, l;
            scanf("%d %d", &w, &l);
            for (int j = ret; j >= 0; j--) {
                int m = min(L[j]-w, l);
                if (m >= L[j+1]) {
                    L[j+1] = m;
                    ret = max(ret, j+1);
                }
            }
        }
        printf("%d\n", ret);
    }

    return 0;
}
