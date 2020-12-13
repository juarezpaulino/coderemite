/* Containers */

#include <stdio.h>

char cont[1001];
char s[50];


int main() {
    
    char ch;
    register int c;
    register int i, j;
    register int pos, d;
    register int ncont;
    register int ns;
    
    c = 1;
    while (1) {
        ncont = 0;
        while ((ch = getchar())) { 
            if (ch == '\n')
                break;
            cont[ncont++] = ch;
        }
        
        if (cont[0] == 'e') break;
        
        ns = 0;
        for (i = ncont-1; i >= 0; i--) {
            d = 50;
            for (j = 0; j < ns; j++)
                if (cont[i] >= s[j])
                    if ((cont[i]-s[j]) < d) {
                        d = s[j]-cont[i];
                        pos = j;
                    }
            if (d == 50) s[ns++] = cont[i];
            else s[pos] = cont[i];
        }
        
        printf("Case %d: %d\n", c, ns);
        c++;
    }
    
    return 0;
}
