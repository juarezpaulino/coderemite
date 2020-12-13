/* Galou is Back */

#include <stdio.h>
#include <stdlib.h>

int r, c;
char m[100][100];
char p[100][100];


void dfs(int i, int j, char k) {
    
    char k1;
    
    if ((i<0)||(i>=r)||(j<0)||(j>=c)||(p[i][j]=='B')||(p[i][j]=='.')) return;
    
    if (k == 'B') {
        p[i][j] = k;
        dfs(i-1, j, k);
        dfs(i-1, j+1, k);
        dfs(i, j-1, k);
        dfs(i, j+1, k);
        dfs(i+1, j-1, k);
        dfs(i+1, j, k);
    }
    else {
        if (p[i][j] == 'F') {
            p[i][j] = k;
            if (k == '(') k1 = ')';
            else k1 = '(';
            dfs(i-1, j, k1);
            dfs(i-1, j+1, k1);
            dfs(i, j-1, k1);
            dfs(i, j+1, k1);
            dfs(i+1, j-1, k1);
            dfs(i+1, j, k1);
        }
        else if (p[i][j] != k) dfs(i, j, 'B');
    }
}


int main() {
    
    int i, j;
    
    while (scanf("%d %d ", &r, &c)) {
        
        if (!r && !c) break;
        
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                m[i][j] = getchar();
                if (m[i][j] == '.') p[i][j] = '.';
                else p[i][j] = 'F';
            }
            getchar();
        }
        
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                if ((m[i][j] == 'I') && (p[i][j] != 'B'))
                    dfs(i, j, '(');
        
        putchar('\n');
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++)
                putchar(p[i][j]);
            putchar('\n');
        }
    }
    
    return 0;
}
