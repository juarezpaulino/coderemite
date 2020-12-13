/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int RET[1010101];

int go(int k) {
    int &ret = RET[k];
    if (ret >= 0) return ret;
    ret = 0;
    int a = (double)k - sqrt(k);
    int b = log((double)k);
    double aux = sin((double)k);
    int c = (double)k * aux*aux;
    ret = (ret + go(a)) % 1000000;
    ret = (ret + go(b)) % 1000000;
    ret = (ret + go(c)) % 1000000;
    return ret;
}

int main() {

    memset(RET, -1, sizeof(RET));
    RET[0] = 1;
    int N;
    while (scanf("%d", &N) && N >= 0) {
        int ret = go(N);
        printf("%d\n", ret);
    }

    return 0;
}
