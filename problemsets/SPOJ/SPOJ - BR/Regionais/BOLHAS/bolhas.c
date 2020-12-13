/* Onde estao as bolhas */

#include <stdio.h>

int n, m;
int val[100000];    /* val[x] -> Vetor desordenado */
int des[100000];    /* des[x] -> Qual a proxima posicao vazio apos x */

/* Procura a primeira posicao vazia depois de x e atualiza todas as posicoes 
da busca */
int search(int x) {
 
    int y;
 
    if (x == des[x]) { des[x] = x+1; return (x); }
    y = search(des[x]);
    
    des[x] = y+1;
    return (y);  
}


int main() {
    
    int i, j;
    int xi;
    
    while (scanf("%d %d", &n, &m)) {
        
        if ((!n) && (!m)) break;
        
        for (i = 0; i < n; i++) { val[i] = 0; des[i] = i; }
        
        for (i = 1; i <= n; i++) {
            if (i <= m) scanf("%d", &xi);
            else xi = 0;
            j = search(xi);
            val[j] = i;
        }
        
        printf("%d", val[0]);
        for (i = 1; i < n; i++) printf(" %d", val[i]);
        putchar('\n');
    }
    
    return 0;
}
