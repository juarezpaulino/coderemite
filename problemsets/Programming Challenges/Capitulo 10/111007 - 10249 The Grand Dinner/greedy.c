/* The Grand Dinner - greedy solution */

#include <stdio.h>

#define MAXTEAMS 70
#define MAXTABLES 50
#define MAXPEOPLE 100

typedef struct {
    int v;
    int original;
} num;


int compare(const void *x, const void *y) {
    
    num *a = (num *)x;
    num *b = (num *)y;
    
    return (b->v - a->v);
}


int main() {

    int m, n;
    num teams[MAXTEAMS];
    int tables[MAXTABLES];
    int t[MAXTEAMS][MAXPEOPLE];
    int pos[MAXTEAMS];
    int i, j;
    
    while (scanf("%d %d", &m, &n)) {
    
        if ((m == 0) && (n == 0))
            break;
        
        for (i = 0; i < m; i++) {
            scanf("%d", &(teams[i].v));
            teams[i].original = i;
        }
        for (i = 0; i < n; i++)
            scanf("%d", &tables[i]);
        qsort(teams, m, sizeof(num), compare);
        
        i = 0;
        if (n >= teams[0].v) {
            for (i = 0; i < m; i++)
                pos[i] = 0;
            for (i = 0; i < m; i++) {
                for (j = 0; (j < n) && (teams[i].v); j++)
                    if (tables[j]) {
                        t[teams[i].original][pos[teams[i].original]] = j+1;
                        pos[teams[i].original]++;
                        tables[j]--;
                        teams[i].v--;
                    }
                if (teams[i].v)
                    break;
            }   
        }
        if (i < m) {
            putchar('0');
            putchar('\n');
        }
        else {
            putchar('1');
            putchar('\n');
            for (i = 0; i < m; i++) {
                for (j = 0; j < pos[i]-1; j++)
                    printf("%d ", t[i][j]);
                printf("%d\n", t[i][j]);
            }
        }
    }
    
    return 0;    
}
