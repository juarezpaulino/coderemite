/* Shell Sort */

#include <stdio.h>
#include <string.h>

char turtles[2][200][82];

int main() {

    int cases, n, i, j;
    char buffer[80];
    
    scanf("%d", &cases);
    while (cases) {
    
        scanf("%d", &n);
        gets(buffer);
        
        for (i = 0; i < 2*n; i++) {
            if (i < n)
                scanf("%[ .a-zA-Z0-9]", turtles[0][i]);
            else
                scanf("%[ .a-zA-Z0-9]", turtles[1][i-n]);
            gets(buffer);
        }
        
        for (i = n-1, j = n-1; i >= 0; i--)
            if (!strcmp(turtles[0][i], turtles[1][j]))
                j--;
        
        for (; j >= 0; j--)
            printf("%s\n", turtles[1][j]);
        
        putchar('\n');
        cases--;
    }
    
    return 0;
}
