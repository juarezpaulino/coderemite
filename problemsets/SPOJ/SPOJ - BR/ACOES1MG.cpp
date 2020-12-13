/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

using namespace std;

int DP[1010101];

int N, K;

int go(int n) {
    int &ret = DP[n];
    if (ret != -1) return ret;
    if (n <= K) return 1;
    if (n%2) ret = go(n/2) + go(n/2+1);
    else ret = 2*go(n/2);
    return ret;
}

int main() {

    while (scanf("%d %d", &N, &K)) {
        if (!(N|K)) break;
        if (N <= K) { puts("1"); continue; }
        for (int i = 1; i <= N; i++) DP[i] = -1;
        int ret = go(N);
        printf("%d\n", ret);
    }

    return 0;
}
