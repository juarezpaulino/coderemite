#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t;
int k;
int c;
char seq[2][2000005];


void generate() {
    
    int i, j;
    char str[2000002];
    
    seq[k^1][0] = '\0';
    for (i = 0; seq[k][i] != '\0'; ) {
        for (j = i+1; seq[k][j] == seq[k][i]; j++);
        sprintf(str, "%d%c", j-i, seq[k][i]);
        strcat(seq[k^1], str);
        i = j;
    }
    
    puts(seq[k^1]);
}


int main() {

    int i;

    scanf("%d ", &t);
    
    k = 0; 
    for (i = 1; i <= t; i++) {
        scanf("%s %d ", seq[k], &c);
        
        puts(seq[k]);
        while (c) { generate(); c--; k ^= 1; }
        
        putchar('\n');
    }
    
    return 0;
}
    
