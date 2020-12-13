/* Arbitrage - DP - trocas de dinheiro ate que seja maior que 1.01 */

#include <stdio.h>

#define MAXD 21
#define ARBITRAGE 1.01

int n;
double table[MAXD][MAXD];

void build_sequence(int parent[][MAXD], int sequence[], int pos, int t) {

    if (parent[pos][t] == -1) return;
    
    sequence[t-1] = parent[pos][t];
    build_sequence(parent, sequence, parent[pos][t], t-1);
}


int main() {
    
    int i, j, k;
    double aux;
    int start, time;
    double max[2][MAXD];
    int parent[MAXD][MAXD], sequence[MAXD];
    char found;
    int best;
    
    while (scanf("%d", &n) != EOF) {
    
        for (i = 0; i < n; i++) {
            for (j = 0; j < i; j++) {
                scanf("%lf", &aux);
                table[i][j] = aux;
            }
            table[i][j] = 1.0;
            for (j = j+1; j < n; j++) {
                scanf("%lf", &aux);
                table[i][j] = aux;
            }
        }
        
        best = n+1;
        for (start = 0; start < n; start++) {
            k = 0;
            found = 0;
            for (i = 0; i < n; i++) {
                max[k][i] = table[start][i];
                parent[i][0] = -1;
                parent[i][1] = start;
                if (max[k][i]*table[i][start] > ARBITRAGE) {
                    found = 1;
                    sequence[0] = start;
                    sequence[1] = i;
                    sequence[2] = start;
                    best = 2;
                }
            }
            if (found)
                break;
                    
            for (time = 2; time < best-1; time++) {
                k ^= 1;
                for (i = 0; i < n; i++)
                    max[k][i] = -1.0;
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++)
                        if (max[k^1][j]*table[j][i] > max[k][i]) {
                            max[k][i] = max[k^1][j]*table[j][i];
                            parent[i][time] = j;
                        }
                    if (max[k][i]*table[i][start] > ARBITRAGE) {
                        found = 1;
                        parent[start][time+1] = i;
                        break;
                    }
                }
                if (found)
                    break; 
            }
            if ((found) && (time+1 < best)) {
                best = time+1;
                sequence[time+1] = start;
                build_sequence(parent, sequence, start, time+1);
            }
        }
        
        if (best > n)
            printf("no arbitrage sequence exists\n");
        else {
            for (i = 0; i < best; i++)
                printf("%d ", sequence[i]+1);
            printf("%d\n", sequence[i]+1);
        }
    }       
    
    return 0;
}
