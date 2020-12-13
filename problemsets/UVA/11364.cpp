/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {

    int T, N, V[20];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        int ret = *max_element(V, V+N) - *min_element(V, V+N);
        printf("%d\n", ret*2);
    }

    return 0;
}
