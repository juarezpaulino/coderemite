/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int K, N;
int DP[101][101];

int go(int k, int v) {
    int &ret = DP[k][v];
    if (ret != -1) return ret;
    if (k == 0) {
        if (v == 0) return ret = 1;
        return ret = 0;
    }
    ret = 0;
    for (int i = 0; i <= min(N,v); i++)
        ret = (ret + go(k-1, v-i)) % 1000000;
    return ret;
}

int main() {

    while (scanf("%d %d", &N, &K)) {
        if (!(N|K)) break;
        memset(DP, -1, sizeof(DP));
        int ret = go(K,N);
        printf("%d\n", ret);
    }

    return 0;
}
