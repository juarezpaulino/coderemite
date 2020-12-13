#include <stdio.h>


int main() {
    
    int n, m;
    int c;
    int s, m1, m2, aux;
    int num[10000];
    int i;
    
    c = 1;
    while (scanf("%d %d", &n, &m)) {
     
        if (!n && !m) break;
        
        for (i = 0; i < n; i++)
            scanf("%d", &num[i]);
        
        s = 0;
        for (i = 0; i < m; i++)
            s += num[i];
        aux = s/m;
        m1 = m2 = aux;
        
        for (; i < n; i++) {
            s += num[i]-num[i-m];
            aux = s/m;
            if (aux < m1) m1 = aux;
            else if (aux > m2) m2 = aux;
        }
        
        printf("Teste %d\n", c++);
        printf("%d %d\n\n", m1, m2);
    }
    
    
    return 0;
}
