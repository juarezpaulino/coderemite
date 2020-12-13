/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long PROFIT[1000000];

long long go(int v) {
    if (v == 0) return 0;
    if (v < 1000000 && PROFIT[v] != -1) return PROFIT[v];
    long long ret = max((long long)v, go(v/4) + go(v/3) + go(v/2));
    if (v < 1000000 && PROFIT[v] == -1) PROFIT[v] = ret;
    return ret;
}

int main() {

    int N;
    memset(PROFIT,-1,sizeof(PROFIT));
    while (scanf("%d", &N) != EOF) {
        long long ret = go(N);
        printf("%lld\n", ret);
    }

    return 0;
}
