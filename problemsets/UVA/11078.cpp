/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int maxi[101010], mini[101010], V[101010];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        maxi[0] = V[0];
        for (int i = 1; i < N; i++) maxi[i] = max(maxi[i-1], V[i]);
        mini[N-2] = V[N-1];
        for (int i = N-3; i >= 0; i--) mini[i] = min(mini[i+1], V[i+1]);
        int ret = V[0]-V[1];
        for (int i = 0; i < N-1; i++) ret = max(ret, maxi[i]-mini[i]);
        printf("%d\n", ret);
    }

    return 0;
}
