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
#include <map>

using namespace std;


int A[5];

int go(int k, int u) {
    if (k == 5) return u == 23;
    int ret = 0;
    if (!ret) ret |= go(k+1, u+A[k]);
    if (!ret) ret |= go(k+1, u-A[k]);
    if (!ret) ret |= go(k+1, u*A[k]);
    return ret;
}

int main() {

    while (1) {
        int t = 0;
        for (int i = 0; i < 5; i++) scanf("%d", A+i), t |= A[i];
        if (!t) break;
        sort(A, A+5);
        int ret = 0;
        do ret = go(1,A[0]); while (!ret && next_permutation(A, A+5));
        if (ret) puts("Possible");
        else puts("Impossible");
    }

    return 0;
}
