#include <stdio.h>
#include <string.h>

char senha[6][10];
char mapa[5][2];


int main() {
    
    int n, x, y;
    char ch, saida[100];
    register int i, j, k = 1;
    while (scanf("%d", &n) && n) {
        memset(senha, 1, sizeof(senha));
        while (n--) {
            for (i = 0; i < 5; i++) {
                scanf("%d %d ", &x, &y); mapa[i][0] = x; mapa[i][1] = y;
            }
            for (i = 0; i < 6; i++) {
                scanf("%c ", &ch);
                for (j = 0; j < 10; j++)
                    if (j != mapa[ch-'A'][0] && j != mapa[ch-'A'][1]) senha[i][j] = 0;
            }
        }
        printf("Teste %d\n", k++);
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 10; j++) if (senha[i][j]) break;
            saida[i<<1] = '0'+j; saida[i<<1|1] = ' ';
        }
        i--; saida[i<<1|1] = 0; printf("%s\n\n", saida);
    }
    return 0;
}

