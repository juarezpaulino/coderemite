/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Seletiva USP 2009 - Problema B - festival.cpp
 * 
 * Tecnica: Problema do troco / DP / BFS
 *
 * Entrada: n blocos e um valor m.
 * Saida: Menor numero de blocos para atingir m.
 *
 * Cuidados: Atentar sempre aos limites do problema: (m <= 1000000). Ou seja,
 * ao utilizar diretamente a técnica, haverá estouro de tempo.
 *
 * Característica: Para driblar o estouro de tempo, deve-se notar que a partir
 * de um certo valor, podemos sempre usar o maior bloco para completar a meta.
 * Qual valor?
 *
 * Seja B o bloco de maior tamanho entre os n blocos. Note que para todo bloco b
 * menor que B (b <= B-1) eh sempre melhor usar b blocos de tamanho B do que
 * B blocos de tamanho b.
 * Neste caso, podemos majorar um alcance A = (B-1)*(B-1)*(N-1), supondo que
 * existam n-1 blocos (todos menos o maior) que sao usados B-1 vezes com um
 * valor de B-1 para cada um.
 * Esse alcance A é o alcance para o qual aplicamos a tecnica do troco. Para
 * alem disso, basta usar o bloco de maior tamanho.
 */ 


#include <stdio.h>

#define INF 0x3F3F3F3F

int fila[100000], f, l;
int bloco[25], troco[250001];
int t, n, m, B, A;

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}


int main() {
    
    int i, j, k, x, y;
    for (t = get_int(); t--; ) {
        n = get_int(); m = get_int();
        for (i = n-1, B = -1; i >= 0; i--) bloco[i] = get_int(), B>?=bloco[i];
        if (n==1) { printf("%d\n", m); continue; }
        A = (n-1)*(B-1)*(B-1);
        for (k = 0; m >= A; m-=B, k++);
        for (i = 1; i <= m; i++) troco[i]=INF; troco[0]=0;
        fila[f=0]=0; l=1;
        while (f!=l && troco[m]==INF) {
            x = fila[f++];
            for (i = 0; i < n; i++) {
                y = x+bloco[i]; j = troco[x]+1;
                if (j<troco[y]) fila[l++]=y, troco[y]=j;
            }
        }
        printf("%d\n", k+troco[m]);
    }
    
    return 0;
}
