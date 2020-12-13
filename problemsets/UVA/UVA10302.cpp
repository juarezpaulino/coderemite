/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

#define SQR(A) ((A)*(A))

int main() {

    long long N;
    while (scanf("%lld", &N) != EOF) {
        printf("%lld\n", SQR((N*(N+1)/2)));
    }

    return 0;
}
