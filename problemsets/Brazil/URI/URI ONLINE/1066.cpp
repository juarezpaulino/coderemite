/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int a;
    int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a);
        if (a%2==0) r1++;
        else r2++;
        if (a > 0) r3++;
        else if (a < 0) r4++;
    }
    printf("%d valor(es) par(es)\n", r1);
    printf("%d valor(es) impar(es)\n", r2);
    printf("%d valor(es) positivo(s)\n", r3);
    printf("%d valor(es) negativo(s)\n", r4);

    return 0;
}
