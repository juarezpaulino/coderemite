#include <stdio.h>

int P, L, I;
int H[151];
int adj[151][151], nadj[151];
char disc[151], mat[151][151];

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch == EOF) exit(0);
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}


int main() {
    
    register int i, j, k, a, b, c = 1;
    char state[2][151];
    
    while (1) {
        P = get_int(); L = get_int(); I = get_int();
        if (!P && !L && !I) break;
        for (i = 1; i <= P; i++)  {
            H[i] = get_int(), nadj[i] = state[0][i] = disc[i] = 0;
            for (j = 1; j <= P; j++) mat[i][j] = 0;
        }
        for (i = 0; i < L; i++) {
            a = get_int(); b = get_int();
            if (H[b] < H[a] && !mat[b][a]) adj[b][nadj[b]++] = a, mat[b][a] = 1;
        }
        state[0][I] = 1; disc[I] = 1;
        k = 0; b = 1;
        while (1) {
            a = 0;
            for (i = 1; i <= P; i++) {
                state[b][i] = 0;
                for (j = 0; j < nadj[i]; j++) 
                    if (state[b^1][adj[i][j]]) { state[b][i] = 1; a = 1; break; }
            }
            if (!a) break; b^=1; k++;
        }
        printf("Teste %d\n%d\n\n", c++, k);
    }
    
    return 0;
}

