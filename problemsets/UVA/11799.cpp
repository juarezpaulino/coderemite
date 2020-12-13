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

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N, ret, k;
        scanf("%d %d", &N, &ret);
        for (int i = 1; i < N; i++) scanf("%d", &k), ret = max(ret, k);
        printf("Case %d: %d\n", t, ret);
    }

    return 0;
}
