/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* ACM/ICPC South America 2003 - Child Play - play.cpp
 * 
 * Técnica: DP / Subset sum
 *
 * Entrada: n pecas de domino
 * Saida: Eh possivel dispor as pecas uma ao lado da outra de tal forma que a
 * soma dos valores na parte de cima das pecas seja igual a soma dos valores
 * embaixo. Se nao, pode-se retirar uma peca e repetir a pergunta.
 * 
 * Descricao: Reduzir o problema a soma de subconjuntos sendo cada valor da
 * soma especificado por val[i] = abs(A[i]-B[i]). Note que val[i] denota a
 * contribuicao de uma peca para o lado que ela esta.
 *
 * Aplicar ordenacao conforme a descricao do problema e aplicar a DP na ordem
 * solicitada, retirando uma peca da DP quando necessario.
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int n;
int A[410], B[410];
int val[410], ord[410];
char possible[400010];

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

int cmp(const void *a, const void *b) {
    int i = *(int *)a, j = *(int *)b, c, d;
    c = A[i]+B[i]; d = A[j]+B[j]; if (c!=d) return c-d;
    c = min(A[i], B[i]), d = min(A[j], B[j]); return c-d;
}

int subset_sum(int s, int out) {
    int i, j, t = s>>1, m = 0;
    if (s&1) return 0;
    for (i = 1; i <= t; i++) possible[i] = 0; possible[0] = 1;
    for (i = 0; i<n && !possible[t]; m+=val[ord[i]], i++) {
        if (ord[i]==out) continue;
        for (j = m; j >= 0; j--) possible[j+val[ord[i]]] |= possible[j];
    }
    return possible[t];
}


int main() {

    int i, s, tot, a, b;

    for (; n = get_int(), n;) {
        for (i = s = tot = 0; i < n; i++) {
            A[i] = get_int(); B[i] = get_int();
            tot += A[i] + B[i]; s += val[i] = abs(A[i]-B[i]);
            ord[i]=i;
        }
        qsort(ord, n, sizeof(int), cmp);
        if (subset_sum(s, -1)) { printf("%d discard none\n", tot>>1); continue; }
        for (i = 0; i < n; i++) {
            if (i && val[ord[i]]==val[ord[i-1]]) continue;
            if (subset_sum(s-val[ord[i]], ord[i])) {
                if (A[ord[i]]<B[ord[i]]) a = A[ord[i]], b = B[ord[i]];
                else b = A[ord[i]], a = B[ord[i]];
                printf("%d discard %d %d\n", (tot-a-b)>>1, a, b);
                break;
            }
        }
        if (i==n) printf("impossible\n");
    }
    
    return 0;
}
