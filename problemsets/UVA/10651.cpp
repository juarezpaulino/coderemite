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

int DP[1<<12];

int go(int g) {
    int &ret = DP[g];
    if (ret != -1) return ret;
    if (!(g & (g<<1))) return ret = __builtin_popcount(g);
    ret = __builtin_popcount(g);
    for (int i = 0; i < 10; i++) {
        if ((g & (1<<i)) && (g & (1<<(i+1))) && (!(g & (1<<(i+2)))))
            ret = min(ret, go(g & (~(1<<i)) & (~(1<<(i+1))) | (1<<(i+2))));
    }
    for (int i = 11; i >= 2; i--) {
        if ((g & (1<<i)) && (g & (1<<(i-1))) && (!(g & (1<<(i-2)))))
            ret = min(ret, go(g & ~(1<<i) & (~(1<<(i-1))) | (1<<(i-2))));
    }
    return ret;
}

int main() {

    memset(DP, -1, sizeof(DP));
    int T;
    scanf("%d", &T);
    while (T--) {
        char A[15];
        scanf("%s", A);
        int a = 0;
        for (int i = 0; i < 12; i++) a = (a<<1) + ((A[i]=='o') ? 1 : 0);
        int ret = go(a);
        printf("%d\n", ret);
    }

    return 0;
}
