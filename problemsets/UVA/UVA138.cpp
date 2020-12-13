/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

int main() {

    int A = 6, B = 8;
    for (int i = 0; i < 10; i++) {
        printf("%10d%10d\n", A, B);
        int A2, B2;
        A2 = 3*A+2*B+1;
        B2 = 4*A+3*B+1;
        A = A2;
        B = B2;
    }

    return 0;
}
