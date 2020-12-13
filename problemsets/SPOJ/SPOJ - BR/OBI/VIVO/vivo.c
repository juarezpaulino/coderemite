#include <stdio.h>
int main() {
    int p, r, k, pos, vencedor;
    int fila[100];
    int inFila[100];
    int ordem, acao;
    int c = 1;
    int i, j;
    
    while (scanf("%d %d", &p, &r)) {
        if (!p && !r) break;
        for (i = 0; i < p; i++) { scanf("%d", &fila[i]); inFila[i] = 1; }
        for (i = 0; i < r; i++) {
            scanf("%d", &k);
            scanf("%d", &ordem);
            pos = 0;
            for (j = 0; j < k; j++) {
                while (!inFila[pos]) pos++;
                scanf("%d", &acao);
                inFila[pos] = !(ordem^acao);
                if (inFila[pos]) vencedor = fila[pos];
                pos++;
            }
        }
        printf("Teste %d\n", c++);
        printf("%d\n\n", vencedor);
    }
    return 0;
}
