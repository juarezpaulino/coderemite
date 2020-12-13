/* Odd or Even */

#include <stdio.h>

int main() {

    int N;
    char mary[101], john[101];
    int aux, i, j, test, wins;
    
    scanf("%d", &N);
    while (N != 0) {
        
        /* Mary */ 
        for (i = 0; i < N; i++){
            scanf("%d", &aux);
            mary[i] = aux;
        } 
        /* John */
        for (i = 0; i < N; i++){
            scanf("%d", &aux);
            john[i] = aux;
        }
        
        wins = 0;
        for (i = 0; i < N; i++) {
            test = 1;
            if (mary[i]%2) {
                for (j = 0; j < N; j++)
                    if ((john[j] != -1) && (!(john[j] % 2))) {
                        john[j] = -1;
                        test = 0;
                        break;
                    }
                if (test) {
                    wins++;
                    for (j = 0; j < N; j++)
                        if ((john[j] != -1) && (john[j] % 2)) {
                            john[j] = -1;
                            break;
                        }
                }
            }
            else {
                for (j = 0; j < N; j++)
                    if ((john[j] != -1) && (john[j] % 2)) {
                        john[j] = -1;
                        test = 0;
                        break;
                    }
                if (test) {
                    wins++;
                    for (j = 0; j < N; j++)
                        if ((john[j] != -1) && (!(john[j] % 2))) {
                            john[j] = -1;
                            break;
                        }
                }
            }
        }
            
        scanf("%d", &N);
            
        printf("%d\n", wins);

            
    }

    return 0;
}
