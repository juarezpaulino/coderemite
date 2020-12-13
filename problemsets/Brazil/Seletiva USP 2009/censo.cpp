/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Seletiva USP 2009 - Problema E - censo.cpp
 * 
 * Solucao 1
 *
 * Tecnica: Ad-hoc / Ordenacao linear
 *
 * Entrada: l entradas de uma matriz esparsa.
 * Saida: Entradas da matriz soma.
 *
 * Tecnica: Implementacao por buckets. Cada linha tem um bucket. Ao inicio,
 * dividimos as entradas em cada balde representando uma linha.
 *
 * Em seguida, processamos cada balde em um vetor auxiliar armazenando a 
 * soma de valores na posicao correspondente a coluna.
 *
 * Processamos novamente o balde, imprimindo linha, coluna e valor.
 *
 * Vantagem: Menos espaco utilizado. Em teoria mais rapido, mas fica mais lento
 * aqui pelo uso da STL e limpeza dos buckets.
 */ 



#include <stdio.h>
#include <list>

#define _foreach(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()


using namespace std;

struct point { int c, v; point(int c, int v) : c(c), v(v) {} };

list<point> bucket[1000001];
int val[1000001];
int t, n, l;

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}


int main() {

    int i, x, y, v;
    for (t = get_int(); t--; ) {
        n = get_int(), l = get_int();
        for (i = 1; i <= n; i++) bucket[i].clear();
        for (i = 0; i < l; i++) {
            get_int(), y = get_int(), x = get_int(), v = get_int();
            bucket[y].push_back(point(x, v));
        }
        for (i = 1; i <= n; i++) {
            foreach(it, all(bucket[i])) val[it->c]+=it->v;
            foreach(it, all(bucket[i])) if (val[it->c])
                printf("%d %d %d\n", i, it->c, val[it->c]), val[it->c] = 0;
        }
        putchar('\n');
    }
    
    return 0;
}
