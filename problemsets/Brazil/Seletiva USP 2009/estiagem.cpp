/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Seletiva USP 2009 - Problema F - estiagem.cpp
 * 
 * Técnica: Ad-hoc
 *
 * Entrada: numero de pessoas e consumo em casas da cidade
 * Saida: Calculo direto de numeros de pessoas com mesmo consumo e consumo medio
 * na cidade.
 *
 * Cuidados: Questoes de arredondamento. Solucao preferivel: conversao do valor
 * total para inteiro, isto e, se a saida possui duas casas decimais,
 * o inteiro de consumo eh multiplicado por 100, efetua a divisao em inteiro e 
 * depois divide por 100 para obter a parte inteira e pega o modulo 100 para
 * parte fracionaria. Usar %02d para imprimir fracionario no printf completando
 * com 0.
 * 
 * Avaliar se a conversao e possivel (se nao estoura o limite dos inteiros):
 * No problema diz que nenhuma casa consome mais de 200m3 e existem no maximo
 * 1000 casas, logo o maior valor e 200.000 que cabe em um inteiro
 * (2.147.483.648).
 *
 * Obs: O uso do mapa da STL economiza memoria e tempo e automaticamente ordena
 * em ordem crescente de consumo.
 *
 */ 


#include <stdio.h>
#include <map>

#define _foreach(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

using namespace std;

map<int, int> mapa;
int n, con, tot;

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}


int main() {
    
    int i, x, y, f, c = 1;
    for (; n = get_int(), n; ) {
        printf("Cidade #%d:\n", c++);
        mapa.clear(); con = tot = 0;
        for (i = 0; i < n; i++)
            x = get_int(), y = get_int(), mapa[y/x]+=x, tot+=x, con+=y;
        f = 0; foreach(it, all(mapa))
            f ? printf(" %d-%d", it->second, it->first) :
                printf("%d-%d", it->second, it->first), f = 1;
        printf("\nConsumo medio: %d.%02d m3.\n\n", ((con*100)/tot)/100, ((con*100)/tot)%100);
    }
    return 0;
}
