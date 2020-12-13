/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Seletiva USP 2009 - Problema E - censo2.cpp
 * 
 * Solucao 2
 *
 * Tecnica: Ad-hoc / Ordenacao linear
 *
 * Entrada: l entradas de uma matriz esparsa.
 * Saida: Entradas da matriz soma.
 *
 * Tecnica: Implementacao por ordenacao linear (counting sort). A ideia e fazer
 * algo similar ao radix sort com os numeros em base 1000000. Basta efetuar
 * duas ordenacoes para linha e em seguida para colunas. Aproveitar a
 * estabilidade do counting sort.
 *
 * Processar as entradas em ordem imprimindo o resultado.
 *
 * Vantagem: Como todos os vetores ja estao alocados, nao e necessario apagar
 * as entradas, tornando a implementacao rapida.
 */ 
 
 
#include <stdio.h>

struct entry {
    int x, y, v;
    entry(){}
    entry(int x, int y, int v) : x(x), y(y), v(v) {}
};


int t, n, l;
int maxy, maxx;
int A[10000001], B[10000001], C[1000001];
entry ent[10000001];


int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}


int main() {

    int i, x, y, v;
    for (t = get_int(); t--; ) {
        n = get_int(), l = get_int(); maxy = maxx = -1;
        for (i = 0; i < l; i++) {
            get_int(), x = get_int(), y = get_int(), v = get_int();
            maxy>?=y, maxx>?=x, ent[i] = entry(x, y, v), A[i] = i;
        }
        
        /* Primeiro counting sort para colunas. */
        for (i = 0; i <= maxy; i++) C[i] = 0;
        for (i = 0; i < l; i++) C[ent[A[i]].y]++;
        for (i = 1; i <= maxy; i++) C[i] += C[i-1];
        for (i = l-1; i >= 0; i--) B[--C[ent[A[i]].y]] = A[i];
        
        /* Segundo counting sort para linhas. */
        for (i = 0; i <= maxx; i++) C[i] = 0;
        for (i = 0; i < l; i++) C[ent[B[i]].x]++;
        for (i = 1; i <= maxx; i++) C[i] += C[i-1];
        for (i = l-1; i >= 0; i--) A[--C[ent[B[i]].x]] = B[i];

        x = ent[A[0]].x, y = ent[A[0]].y;
        for (i = v = 0; i < l; i++) {
            if (x!=ent[A[i]].x || y!=ent[A[i]].y) {
                printf("%d %d %d\n", x, y, v);
                x = ent[A[i]].x, y = ent[A[i]].y, v = 0;
            }
            v += ent[A[i]].v;
        }
        printf("%d %d %d\n\n", x, y, v);
    }
    
    return 0;
}
