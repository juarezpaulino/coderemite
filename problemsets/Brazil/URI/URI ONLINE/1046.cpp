/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int a, b;
    scanf("%d%d", &a, &b);
    if (a == b) puts("O JOGO DUROU 24 HORA(S)");
    else if (b < a) printf("O JOGO DUROU %d HORA(S)\n", 24-a+b);
    else printf("O JOGO DUROU %d HORA(S)\n", b-a);

    return 0;
}
