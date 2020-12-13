/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int V[2020202];

int main() {

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        sort(V, V+N);
        int ret = 0;
        for (int i = 0; i < N/2; i++)
            ret = max(ret, V[i]+V[N-i-1]);
        printf("%d\n", ret);
    }

    return 0;
}
