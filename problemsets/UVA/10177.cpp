/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    long long N, V1, S1, S2, S3;
    while (scanf("%lld", &N) != EOF) {
        V1 = N*(N+1)/2;
        S1 = V1*(2*N+1)/3;
        S2 = V1*V1;
        S3 = S1*(3*N*N+3*N-1)/5;
        printf("%lld %lld %lld %lld %lld %lld\n",
                S1,
                V1*V1 - S1,
                S2,
                V1*V1*V1 - S2,
                S3,
                V1*V1*V1*V1 - S3);
    }

    return 0;
}
