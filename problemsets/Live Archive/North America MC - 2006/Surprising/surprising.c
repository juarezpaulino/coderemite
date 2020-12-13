/* Surprising */

#include <stdio.h>
#include <string.h>

char str[200];
int size;

int dpairs(int d) {

    int i, j;
    char pair[200][2];
    int n = 0;
    
    for (i = 0; i < size-(d+1); i++) {
        pair[n][0] = str[i];
        pair[n++][1] = str[i+d+1];
    }
    
    for (i = 0; i < n; i++)
        for (j = i+1; j < n; j++)
            if ((pair[i][0] == pair[j][0]) && (pair[i][1] == pair[j][1])) 
                return (0);
    return (1);
}


int main() {

    int i;

    while (scanf("%s ", str)) {
        
        if (str[0] == '*') break;
        
        size = strlen(str);
        for (i = 0; i <= size-3; i++)
            if (!dpairs(i)) break;
        
        if (i <= size-3) printf("%s is NOT surprising.\n", str);
        else printf("%s is surprising.\n");
    }
    
    return 0;
}
