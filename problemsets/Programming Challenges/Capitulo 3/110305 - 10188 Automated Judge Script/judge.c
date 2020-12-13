/* Automated Judge Script */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char solution[10003];
char input[10003];
char aux1[10003], aux2[10003];


int main() {
    
    int m, n, run, i, k, size;
    char acc, line[103];
    
    run = 1; 
    while (1) {
        gets(line);
        sscanf(line, "%d", &m);
        
        if (m == 0)
            break;    
        
        solution[0] = '\0';
        for (i = 0; i < m; i++) {
            gets(line);
            strcat(line, "\n");
            strcat(solution, line);
        }   
        
        gets(line);
        sscanf(line, "%d", &n);
        
        input[0] = '\0';
        for (i = 0; i < n; i++) {
            gets(line);
            strcat(line, "\n");
            strcat(input, line);
        }   
        
        acc = 0;
        /* Accepted */
        if (m == n) {
            acc = 1;
            for (i = 0; i < m; i++)
                if (strcmp(input, solution))
                    acc = 0;
            if (acc) {
                printf("Run #%d: Accepted\n", run);
                run++;
            }
        }
        /* Presentation Error and wrong answer. */
        if (!acc) {
            size = strlen(solution);
            for (i = 0, k = 0; i < size; i++)
                if (isdigit(solution[i])) {
                    aux1[k] = solution[i];
                    k++;
                }
            aux1[k] = '\0';
            size = strlen(input);
            for (i = 0, k = 0; i < size; i++)
                if (isdigit(input[i])) {
                    aux2[k] = input[i];
                    k++;
                }
            aux2[k] = '\0';
            if (!strcmp(aux1, aux2))
                printf("Run #%d: Presentation Error\n", run);
            else
                printf("Run #%d: Wrong Answer\n", run);
            run++;
        }
    }
    return 0;
}
