/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int A, B, C, X, Y, Z;
    scanf("%d %d %d %d %d %d", &A, &B, &C, &X, &Y, &Z);
    int ret = (X/A) * (Y/B) * (Z/C);
    printf("%d\n", ret);

    return 0;
}
