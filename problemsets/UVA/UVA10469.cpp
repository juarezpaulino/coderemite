/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {

    unsigned int A, B;
    while (scanf("%u %u", &A, &B) != EOF) {
        printf("%u\n", A^B);
    }

    return 0;
}
