/* Where's Waldorf? */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char grid[51][51];
int m, n;

void read_grid() {

    int i, j;
    
    scanf("%d %d", &m, &n);
    getchar();
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++)
            grid[i][j] = toupper(getchar());
        getchar();
    }
}
    
int check(char *word, int x, int y, int size) {

    int i;
    char directions[8] = {1,1,1,1,1,1,1,1};
    
    for (i = 0; i < size; i++) {
        if ((x-i) > 0) {
            if (word[i] != grid[x-i][y])
                directions[0] = 0;
        }
        else
            directions[0] = 0;
        if ((x+i) <= m) {
            if (word[i] != grid[x+i][y])
                directions[1] = 0;
        }
        else
            directions[1] = 0;    
        if ((y-i) > 0) {
            if (word[i] != grid[x][y-i])
                directions[2] = 0;
        }
        else
            directions[2] = 0;
        if ((y+i) <= n) {
            if (word[i] != grid[x][y+i])
                directions[3] = 0;
        }
        else
            directions[3] = 0;
        if (((x-i) > 0) && ((y-i) > 0)) {
            if (word[i] != grid[x-i][y-i])
                directions[4] = 0;
        }
        else
            directions[4] = 0;    
        if (((x-i) > 0) && ((y+i) <= n)) {
            if (word[i] != grid[x-i][y+i])
                directions[5] = 0;
        }
        else
            directions[5] = 0;
        if (((x+i) <= m) && ((y-i) > 0)) {
            if (word[i] != grid[x+i][y-i])
                directions[6] = 0;
        }
        else
            directions[6] = 0;
        if (((x+i) <= m) && ((y+i) <= n)) {
            if (word[i] != grid[x+i][y+i])
                directions[7] = 0;
        }
        else
            directions[7] = 0;
    }
    
    for (i = 0; i < 8; i++)
        if (directions[i] == 1)
            return 1;
    return 0;    
}


int main() {

    int cases, k, i, j, l, size;
    char name[82], found;
    
    scanf("%d", &cases);
    getchar();
    while (cases) {
        getchar();
        read_grid();
        
        scanf("%d", &k);
        getchar();
        for (i = 0; i < k; i++) {
            fgets(name, 82, stdin);
            size = strlen(name) - 1;
            name[size] = '\0';
            for (j = 0; j < size; j++)
                name[j] = toupper(name[j]);
            for (j = 1, found = 0; ((j <= m) && (!found)); j++)
                for (l = 1; l <= n; l++)
                    if (check(name, j, l, size)) {
                        printf("%d %d\n", j, l);
                        found = 1;
                        break;
                    }
        }
        
        if (cases > 1)
            putchar('\n');
        
        cases--;
    }
    return 0;
}
