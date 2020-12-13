/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Seletiva USP 2009 - Problema C - mestrexu.cpp
 * 
 * Tecnica: Ad-hoc / Guloso
 *
 * Entrada: n blocos.
 * Saida: Responder sim ou nao se o algoritmo guloso e otimo na quantidade
 * minima de blocos necessaria.
 *
 * Tecnica: Implementacao do teste de pearson: Entradas M() - otimo G() - guloso
 * M(w) concorda com G(coin(i-1)-1) nas entradas de 1 a j-1 e com a quantidade
 * de blocos na entrada j (+1). Ou seja w = Total(G(1->j-1)) + coin[j]*(G[j]+1)
 * Iterar sobre i e j. Complexidade: O(n^3). 
 */ 


#include <stdio.h>
#include <stdlib.h>

int t, n, coin[400];

/*******************************************************************************
 * Algoritmo guloso para o problema do troco. O vetor G guarda as entradas.
 * Requer ordenacao decrescente fo valor das moedas em coin[n]. O(n)
 */
inline int greedy(int w, int G[]) {
    int i, s = 0;
    for (i = 0; i < n; i++) s+=G[i]=w/coin[i], w-=G[i]*coin[i];
    return s;
}

/*******************************************************************************
 * Teste de Pearson para verificar se o guloso corresponde ao otimo. Requer
 * ordenacao decrescente do valor das moedas em coin[n]. O(n^3)
 * Dep: greedy
 */
int pearson() {
    int i, j, k, w;
    int M[400], ms, G[400], gs;
    for (i = n-2; i > 0; i--) { greedy(coin[i-1]-1, M); for (j = n-2; j >= i; j--) {
        for (w=ms=k=0; k <= j; k++) w+=M[k]*coin[k], ms+=M[k];
        w+=coin[j]; ms++;
        gs = greedy(w, G); if (ms<gs) return 0;
    } }
    return 1;
}


int cmp(const void *a, const void *b) { return (*(int *)b-*(int *)a); }

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}


int main() {
    int i;
    for (t = get_int(); t--; ) {
        n = get_int(); for (i = n-1; i >= 0; i--) coin[i] = get_int();
        qsort(coin, n, sizeof(int), cmp);
        if (pearson()) printf("sim\n"); else printf("nao\n");
    }
    return 0;
}


/* Resolvendo com DP. 
int MyCode(vector<int> a) {
  set<int> d;
  for (int i(0); i < a.size(); ++i)
    d.insert(-a[i]);
  vector<int> den;
  Forc(i, d)
    den.push_back(*i);
  int n(den.size());
  vector<int> greedy(1000001), dp(1000001);
  greedy[0] = 0;
  dp[0] = 0;
  for (int i(1); i <= 1000000; ++i) {
    for (int j(0); j < n; ++j)
      if (i + den[j] >= 0) {
        greedy[i] = greedy[i + den[j]] + 1;
        break;
      }
    dp[i] = dp[i - 1] + 1;
    for (int j(0); j < n; ++j)
      if (i + den[j] >= 0)
        dp[i] <?= dp[i + den[j]] + 1;
    if (greedy[i] != dp[i]) return i;
  }
  return -1;
} */
