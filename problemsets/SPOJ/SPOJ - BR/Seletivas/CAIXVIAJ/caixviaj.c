#include <stdio.h>

int adj[101][101];
char fim[101];
int c, s, e, t;
int lucro[2][101];

int get_int() {

    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');

    return i;
}


int main() {
    
    int i, j, k, x, d;
    int nv;
    
    while (1) {
        c = get_int(); s = get_int(); e = get_int(); t = get_int();
        if (!c && !s && !e && !t) break;
        for (i = 1; i <= c; i++) {
            for (j = 1; j <= c; j++)
                adj[i][j] = get_int();
            fim[i] = 0;
        }
        for (i = 0; i < e; i++) { x = get_int(); fim[x] = 1; }
        for (i = 1; i <= c; i++) lucro[0][i] = adj[s][i]; nv = 1;
        for (k = 1; k < t; k++) {
            for (j = 1; j <= c; j++) {
                lucro[nv][j] = 0;
                for (i = 1; i <= c; i++)
                    if ((d = lucro[nv^1][i] + adj[i][j]) > lucro[nv][j])
                        lucro[nv][j] = d;
            }
            nv^=1;
        }
        
        d = 0; nv^=1;
        for (i = 1; i <= c; i++) if (fim[i] && lucro[nv][i]>d) d = lucro[nv][i];
        printf("%d\n", d);
    }
    
    return 0;
}
