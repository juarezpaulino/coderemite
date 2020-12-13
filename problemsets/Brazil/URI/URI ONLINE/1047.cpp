/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int a, b, c, d;
    scanf("%d%d%d%d", &a, &c, &b, &d);
    if (a==b && c==d) puts("O JOGO DUROU 24 HORA(S) E 0 MINUTO(S)");
    else if (a==b && c < d) printf("O JOGO DUROU 0 HORA(S) E %d MINUTO(S)\n", d-c);
    else if (a==b && c > d) printf("O JOGO DUROU 23 HORA(S) E %d MINUTO(S)\n", (60-c+d)%60);
    else if (b < a) printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", (23-a+b)+(60-c+d)/60, (60-c+d)%60);
    else printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", b-a-1+(60-c+d)/60, (60-c+d)%60);

    return 0;
}
