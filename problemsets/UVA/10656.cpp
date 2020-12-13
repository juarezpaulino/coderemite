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

    int N, V[1010];
    while (1) {
        scanf("%d", &N);
        if (N==0) break;
        int k = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", V+k);
            if (V[k]!=0) k++;
        }
        if (k==0) { puts("0"); continue; }
        for (int i = 0; i < k-1; i++) printf("%d ", V[i]);
        printf("%d\n", V[k-1]);
    }

    return 0;
}
