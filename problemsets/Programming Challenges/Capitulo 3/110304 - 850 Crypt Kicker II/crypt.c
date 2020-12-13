/* Crypt Kicker II */

#include <stdio.h>
#include <string.h>

char key[] = "the quick brown fox jumps over the lazy dog";
char change[26];

char encrypted[103][85];

int read_encrypted() {

    int num = 0;
    char ch;
    
    while (fgets(encrypted[num], 100, stdin)) {
        
        if (*encrypted[num] == '\n')
            break;
        
        encrypted[num][strlen(encrypted[num]) - 1] = '\0';
        num++;
    }
    if (num == 0)
        while (((ch = getchar()) != '\n') && (ch != EOF));

    return (num);   
}

int main() {
    
    int cases;
    int lines, i, j;
    char found, aux[44];
    
    scanf("%d", &cases);
    getchar();
    getchar();
    while (cases) {
        
        lines = read_encrypted();
        
        /* Searching the key - constructing the change */
        found = 0;
        for (i = 0; (i < lines) && (!found); i++) {
            if (strlen(encrypted[i]) == 43) {
                for (j = 0; j < 26; j++)
                    change[j] = -1;
                for (j = 0; j < 43; j++) {
                    if (key[j] != ' ') {
                        if (change[encrypted[i][j] - 'a'] == -1) {
                            change[encrypted[i][j] - 'a'] = key[j];
                            aux[j] = key[j];
                        }
                        else
                            aux[j] = change[encrypted[i][j] - 'a'];
                    }
                    else
                        aux[j] = encrypted[i][j];
                }
                aux[j] = '\0';
                if (!strcmp(aux, key))
                    found = 1;
            }
        }
        
        if (!found)
            printf("No solution.\n");
        else {
            for (i = 0; i < lines; i++) {
                for (j = 0; encrypted[i][j] != '\0'; j++)
                    if (encrypted[i][j] != ' ')
                        putchar(change[encrypted[i][j] - 'a']);
                    else
                        putchar(' ');
                putchar('\n');
            }
        }     
        
        if (cases > 1)
            putchar('\n');
        cases--;
    }
    return 0;
}
