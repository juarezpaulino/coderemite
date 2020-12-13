/* Bridge */

#include <stdio.h>
#include <stdlib.h>

#define MAXPEOPLE 1000

int n;
int p[MAXPEOPLE];
int move[3*MAXPEOPLE];
int m;

int compare(int *a, int *b) {
    
    return (*a - *b);
}


int main() {
    
    int cases;
    int i;
    int s1, s2;
    int total;
    char line[80];
    int compare();
    
    scanf("%d", &cases);
    while(cases) {
        
        scanf("%d", &n);
        
        for (i = 0; i < n; i++)
            scanf("%d", &p[i]);
        getchar();
        while (gets(line))
            if (*line == '\0')
                break;
                
        if (n == 0)
            printf("0\n");
        else if (n == 1)
            printf("%d\n%d\n", p[0], p[0]);
        else {
            qsort(p, n, sizeof(int), compare);
            total = 0;
            m = 0;
            while (n > 3) {
                s1 = p[0] + (2*p[1]) + p[n-1];
                s2 = (2*p[0]) + p[n-1] + p[n-2];
                if (s1 < s2) {
                    move[m] = p[0];
                    move[m+1] = p[1];
                    move[m+2] = p[0];
                    move[m+3] = p[n-2];
                    move[m+4] = p[n-1];
                    move[m+5] = p[1];
                    total += s1;
                }
                else {
                    move[m] = p[0];
                    move[m+1] = p[n-1];
                    move[m+2] = p[0];
                    move[m+3] = p[0];
                    move[m+4] = p[n-2];
                    move[m+5] = p[0];
                    total += s2;
                }
                n -= 2;
                m += 6;
            }
            if (n == 3) {
                total += p[0]+p[1]+p[2];
                move[m] = p[0];
                move[m+1] = p[2];
                move[m+2] = p[0];
                move[m+3] = p[0];
                move[m+4] = p[1];
                m += 5; 
            }
            else {
                total += p[1];
                move[m] = p[0];
                move[m+1] = p[1];
                m += 2;
            }
            printf("%d\n", total);
            for (i = 0; i < m-2; i+=3)
                printf("%d %d\n%d\n", move[i], move[i+1], move[i+2]);
            printf("%d %d\n", move[m-2], move[m-1]);
        }
        
        cases--;
        if (cases > 0)
            putchar('\n');
    }
    
    return 0;
}
