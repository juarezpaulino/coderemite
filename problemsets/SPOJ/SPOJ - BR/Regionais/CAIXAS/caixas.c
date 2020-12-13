/* Desempilhando Caixas */

#include <stdio.h>

int n, p;
int nc[1000];


int main() {
 
    int i, j;
    int id;
    int pil, pos;
    int esq, dir;
 
    while (scanf("%d %d", &n, &p)) {
     
        if ((!n) && (!p)) break;
        
        for (i = 0; i < p; i++) {
            scanf("%d", &nc[i]);
            for (j = 0; j < nc[i]; j++) {
                scanf("%d", &id);
                if (id == 1) { pil = i; pos = j+1; }
            }
        }
        
        esq = dir = nc[pil]-pos;
        /* Esquerda */
        for (i = pil-1; i >= 0; i--) {
            if (nc[i] < pos) break;
            esq = esq + nc[i]-pos+1;
        }
        /* Direita */
        for (i = pil+1; i < p; i++) {
            if (nc[i] < pos) break;
            dir = dir + nc[i]-pos+1;
        }
        
        if (esq < dir) printf("%d\n", esq);
        else printf("%d\n", dir);
    }
    
    return 0;
}
