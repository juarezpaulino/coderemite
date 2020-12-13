/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int N, C[100];

int go(int k) {
    if (C[k]!=-1) return C[k];
    if (k >= N) return 0;
    int &ret = C[k];
    ret = 0;
    ret += go(k+2) + go(k+3);
    if (ret == 0) ret = 1;
    return ret;
}

int main() {

    while (scanf("%d", &N) != EOF) {
        memset(C,-1,sizeof(C));
        int ret = go(0) + go(1);
        printf("%d\n", ret);
    }

    return 0;
}
