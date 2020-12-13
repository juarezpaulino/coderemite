/* Pascal Library */

#include <stdio.h>

char aluno[100];

int main() {
    
    int n, d;
    int aux;
    int i, j;
    
    while (scanf("%d %d", &n, &d)) {
        
        if (n == 0 && d == 0) break;
        
        for (i = 0; i < n; i++) aluno[i] = 1;
        
        for (i = 0; i < d; i++)
            for (j = 0; j < n; j++) {
                scanf("%d", &aux);
                if (aluno[j]) aluno[j] = aux;
            }
        
        for (i = 0; i < n; i++) if (aluno[i]) break;
        
        if (i == n) printf("no\n");
        else printf("yes\n");
    }
    
    return 0;
}
