/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int N;

int pow(int N, int K) {
    if (K <= 0) return 1;
    int ret = pow(N, K/2);
    ret *= ret;
    if (K&1) ret *= N;
    return ret;
}

int main() {

    int id = 1;
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        printf("Case %d, N = %d, # of different labelings = %d\n", id, N, pow(N,N-2));
        id++;
    }

    return 0;
}
