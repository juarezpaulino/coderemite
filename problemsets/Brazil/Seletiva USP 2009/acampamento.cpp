/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Seletiva USP 2009 - Problema G - acampamento.cpp
 *
 * Técnica: Ad-hoc / Simulacao
 *
 * Entrada: numero e nome das criancas em sentido anti-horario e valor das fichas.
 * Saida: Ultima crianca a sair do circulo.
 *
 * Cuidados: Verificar uma forma simples e eficiente de realizar a simulacao.
 *
 * 1. Observe que o valor da ficha eh <= 500 mas so existem 100 criancas logo em
 * cada etapa e possivel pegar apenas o modulo do valor da ficha pelo numero
 * de criancas restantes.
 *
 * 2. O mais rapido e simples de se implementar eh montando dois vetores e
 * alternando entre eles. Nos vetores soh existem criancas que ainda estao no
 * jogo. Ha outras opcoes como lista encadeada mas dao mais trabalho. Mas se usar
 * a lista da STL é o melhor jeito.
 *
 */

#include <stdio.h>

#define MAXV 110

int n;
// Indica o idice da crianca no circulo c que ocupa a i-esima posicao.
int circ[2][110], c;
char nome[110][35];
int val[110];

int main() {

    int i, j, v, t, p;     // v e t - numero de elementos a contar; p - posicao

    for (; scanf("%d ", &n), n;) {
        for (i = 0; i < n; i++) scanf("%s %d", nome[i], &val[i]), circ[0][i] = i;

        c = p = 0; v = val[circ[c][p]];
        for (i = 0; i < n-1; i++, c^=1) {
            // Calcula a posicao que sera retirada.
            t = v%(n-i);
            (v&1) ? p=(p+t)%(n-i) : p=(p+(n-i)-t)%(n-i);

            // Copia as criancas vivas para o outro circulo.
            for (j = 0; j < p; j++) circ[c^1][j] = circ[c][j];
            for (j = p+1; j < n-i; j++) circ[c^1][j-1] = circ[c][j];

            // Calcula a posicao da proxima crianca que deve se iniciar a
            // contagem.
            v = val[circ[c][p]];
            (v&1) ? p=(p+(n-i-1)-1)%(n-i-1) : p=p%(n-i-1);
        }
        printf("Vencedor(a): %s\n", nome[circ[c][0]]);
    }
    return 0;
}
