/* Australian Voting */

/*#define _DEBUG*/


#include <stdio.h>

#define MAX_CANDIDATES 25
#define MAX_LINES 1020

/* Important Variables */
int matrix[MAX_LINES][MAX_CANDIDATES];
int votes[MAX_CANDIDATES];
char candidates[MAX_CANDIDATES][90];
char valid_candidates[MAX_CANDIDATES];

int main(){
    
    /* Usable variables */
    int cases;
    int n;
    int num_ballots, valid_votes; 
    int elected, min, tied;
    
    /* Counters and auxiliar variables */
    int i,j,k;
    char ballot[82];
    char number[3];
    
    scanf("%d", &cases);
    getchar();
    getchar();
    while(cases) {

        /* Number of candidates */
        scanf("%d", &n);
        getchar();

        /* Name scan */
        for (i = 0; i < n; i++)
            fgets(candidates[i], 90, stdin);
            
        /* Ballots Scan */
        num_ballots = 0;   
        do {
            if (!fgets(ballot, 82, stdin))
                break;
            if ((*ballot == EOF) || ((*ballot == '\n')))
                break;
            i = 0;
            while (ballot[i] == ' ')
                i++;
            for (k = 0, j = 0; ; i++) {
                if ((ballot[i] == ' ') || (ballot[i] == '\n')) {
                    number[j] = '\0';
                    sscanf(number, "%d", &matrix[num_ballots][k]);
                    k++;
                    j = 0;
                    if (ballot[i] == ' ')
                        while (ballot[i+1] == ' ')
                            i++;
                }
                else {
                    number[j] = ballot[i];
                    j++;
                }
                if ((ballot[i] == '\n') || (ballot[i] == EOF))
                    break;
            }
            num_ballots++;
            
        } while (*ballot != '\n');

        /* Calculus */
        for (i = 0; i < n; i++)
            valid_candidates[i] = 1;
            
        for (;;) {
            
            valid_votes = 0;
            
            for (i = 0; i < n; i++)
                votes[i] = 0;
                
            for (i = 0; i < num_ballots; i++) {
                for (k = 0; (k < n) && (!valid_candidates[matrix[i][k] - 1]); k++);
                if (k < n) {
                    votes[matrix[i][k] - 1]++;
                    valid_votes++;
                }
            }
            
            #ifdef _DEBUG
            for (i = 0; i < n; i++)
                printf("%d - %d\n", i, votes[i]);
            #endif
                
            min = 2000;
            tied = 1;
            elected = -1;
                        
            for (i = 0; (i < n) && (elected == -1); i++) {
                if (valid_candidates[i]) {
                    if (votes[i] < min)
                        min = votes[i];
                    if (votes[i] > valid_votes/2)
                        elected = i;
                }
            }
            
            for (i = 0; i < n; i++)
                if (valid_candidates[i])
                    if (votes[i] != min) {
                        tied = 0;
                        break;
                    }
            #ifdef _DEBUG
            printf("elected: %d - tied: %d - min: %d\n", elected, tied, min);
            #endif
            
            if (!tied)
                for (i = 0; i < n; i++)
                    if (votes[i] == min)
                        valid_candidates[i] = 0;
            
            if ((elected != -1) || (tied))
                break;
        }
        
        if (elected != -1)
            printf(candidates[elected]);
        else
            for (i = 0; i < n; i++)
                if (valid_candidates[i])
                    printf(candidates[i]);

        if (cases > 1)
            putchar('\n');
   
        cases--;

    }
    
    return 0;
}
