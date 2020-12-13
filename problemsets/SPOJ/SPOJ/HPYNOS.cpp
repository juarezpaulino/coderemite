/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

#define SQR(x) ((x)*(x))

int H[1000];

int HAPPY(int N) {
    if (N == 1) return 1;
    if (N < 1000) {
        if (H[N] >= 0) return H[N];
        else if (H[N]==-2) return H[N] = 0;
    }
    if (N < 1000) H[N] = -2;
    int N2 = 0;
    while (N) { N2 += SQR(N%10); N/=10; }
    int ret = HAPPY(N2);
    if (N < 1000) H[N] = (ret > 0) ? ret+1 : ret;
    return (ret > 0) ? ret+1 : ret;
}


int main() {

    int N;
    for (int i = 0; i < 1000; i++) H[i] = -1;
    scanf("%d", &N);
    int ret = HAPPY(N);
    printf((ret <= 0) ? "-1\n" : "%d\n", ret-1);

    return 0;
}
