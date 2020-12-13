/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Seletiva USP 2009 - Problema J - dias.cpp
 * 
 * Tecnica: Ad-hoc
 *
 * Entrada: d1 e d2 dias do mes no planeta 1 e 2.
 * Saida: mmc(d1, d2) = combinacoes possiveis de dias simultaneos nos dois
 * planetas modulo 1713371337.
 *
 * Cuidados: Estouro de inteiro pelos limites do problema. Usar long long.
 */ 


#include <stdio.h>

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template <class T> T abs(T a)      { return a < 0 ? -a : a; }

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}


int main() {
    long long d1, d2;
    for (; d1 = get_int(), d2 = get_int(), d1+d2; ) printf("%d\n", (int)(lcm(d1, d2)%1713371337));
    return 0;
}
