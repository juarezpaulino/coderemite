/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int DP[1000001];
int K, L, M;

int main() {

    scanf("%d %d %d", &K, &L, &M);

    for (int i = 1; i <= 1000000; i++) {
        if (!DP[i-1]) DP[i] = 1;
        else if (i>=K && !DP[i-K]) DP[i] = 1;
        else if (i>=L && !DP[i-L]) DP[i] = 1;
    }

    while(M--) {
        int x; scanf("%d", &x);
        putchar('B'-DP[x]);
    }
    putchar('\n');

    return 0;
}
