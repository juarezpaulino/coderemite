/* File Fragmentation */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lines;
char fragments[290][150];
char valid_fragments[290];
char aux1[260];
char aux2[260];

int compare(const void *x, const void *y) {
    
    return(strlen((char *) x) - strlen((char *) y));
}

void read_fragments() {
    
    lines = 0;
    while (fgets(fragments[lines], 150, stdin)) {
        
        if (*fragments[lines] == '\n')
            break;
        
        if (fragments[lines][strlen(fragments[lines]) - 1] == '\n')
            fragments[lines][strlen(fragments[lines]) - 1] = '\0';
        lines++;
    }
}

int search_pattern(int pos, char *pattern, int *size_pattern) {

    int i;
    
    *aux1 = '\0';
    *aux2 = '\0';
    for (i = lines - 1; (i >= lines/2); i--) {
        if (valid_fragments[i]) {
            if (strlen(fragments[i]) == (*size_pattern - strlen(fragments[pos]))) {
                strcat(aux1, fragments[pos]);
                strcat(aux1, fragments[i]);
                strcat(aux2, fragments[i]);
                strcat(aux2, fragments[pos]);
                valid_fragments[i] = 0;
                if (*pattern == '\0') {
                    if ((pos + 1) < lines/2) {
                        if (search_pattern(pos + 1, aux1, size_pattern)) {
                            strcpy(pattern, aux1);
                            return 1;
                        }
                        if (search_pattern(pos + 1, aux2, size_pattern)) {
                            strcpy(pattern, aux2);
                            return 1;
                        }
                        valid_fragments[i] = 1;
                    }
                }
                else {
                    if ((pos + 1) < lines/2) {
                        if (!strcmp(aux1, pattern))
                            if (search_pattern(pos + 1, pattern, size_pattern))
                                return 1;
                        if (!strcmp(aux2, pattern))
                            if (search_pattern(pos + 1, pattern, size_pattern))
                                return 1;
                        valid_fragments[i] = 1;
                    }
                    else
                        return 1;
                }
            }
        }
    }
    return 0;

}        

int main() {

    int cases, size_pattern, i;
    char pattern[260];
    
    scanf("%d", &cases);
    getchar();
    getchar();
    while (cases) {
        
        read_fragments();
        
        qsort(fragments, lines, sizeof(char) * 150, compare);
        
        for (i = 0; i < lines; i++)
            valid_fragments[i] = 1;
        
        *pattern = '\0';
        if (lines > 2)
            size_pattern = strlen(fragments[0]) + strlen(fragments[lines - 1]);
        else {
            strcat(pattern, fragments[0]);
            strcat(pattern, fragments[1]);
        }
            
        search_pattern(0, pattern, &size_pattern);
     
        printf("%s\n", pattern);
        
        if (cases > 1)
            putchar('\n');   
        cases--;
    }
    
    return 0;
}
