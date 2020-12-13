/* Sudoku */

#include <stdio.h>


char sud[16][16];
char quad[4][4][16];
char finish;


void sudoku(int k) {
    
    int i, j, u;
    int qx, qy;
    int c, m;
    int x, y;
    char aux[16], cand[16];
    
    if (k == 256) { finish = 1; return; }
    
    m = 1000000000;
    for (i = 0; i < 16; i++)
        for (j = 0; j < 16; j++) {
            if (sud[i][j] != '-') continue;
            qx = i/4; qy = j%4;
            for (u = 0; u < 16; u++) 
                if (quad[qx][qy][u]) aux[u] = 1;
                else aux[u] = 0;
            /* up */
            for (u = i-1; u >= 0; u--) if ((sud[u][j] != '-') && (!aux[sud[u][j]-'A'])) aux[sud[u][j]-'A'] = 1;
            /* left */
            for (u = j-1; u >= 0; u--) if ((sud[i][u] != '-') && (!aux[sud[i][u]-'A'])) aux[sud[i][u]-'A'] = 1;
            /* down */
            for (u = i+1; u < 16; u++) if ((sud[u][j] != '-') && (!aux[sud[u][j]-'A'])) aux[sud[u][j]-'A'] = 1;
            /* right */
            for (u = j+1; u < 16; u++) if ((sud[i][u] != '-') && (!aux[sud[i][u]-'A'])) aux[sud[i][u]-'A'] = 1;
            
            c = 0;
            for (u = 0; u < 16; u++) if (!aux[u]) c++;
            
            if (c < m) {
                m = c;
                x = i; y = j;
                for (u = 0; u < 16; u++) cand[u] = aux[u];
            }
        }
        
    for (i = 0; i < 16; i++)
        if (!cand[i]) {
            qx = x/4; qy = y%4;
            quad[qx][qy][i] = 1;
            sud[x][y] = i+'A';
            sudoku(k+1);
            if (finish) return;
            sud[x][y] = '-';
            quad[qx][qy][i] = 0;
        }
}


int main() {
    
    int i, j, k;
    char flag;
    char ch;
    int q_cmp();
    
    flag = 0;
    while (1) {
        
        for (i = 0; i < 4; i++) 
            for (j = 0; j < 4; j++)
                for (k = 0; k < 16; k++)
                    quad[i][j][k] = 0;
        k = 0;
        for (i = 0; i < 16; i++) {
            for (j = 0; j < 16; j++) {
                sud[i][j] = getchar();
                if (sud[i][j] != '-') {
                    k++;
                    quad[i/4][j%4][sud[i][j]-'A'] = 1;
                }
            }
            while ((ch = getchar()) != '\n') if (ch == EOF) return 0;
        }
        
        if (flag) putchar('\n');
        
        finish = 0;
        sudoku(k);
        
        for (i = 0; i < 16; i++) {
            for (j = 0; j < 16; j++)
                putchar(sud[i][j]);
            putchar('\n');
        }
        flag = 1;
        
        while ((ch = getchar()) != '\n') if (ch == EOF) return 0;
    }
}
