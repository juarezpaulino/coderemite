#include <stdio.h>

typedef long long symb;

symb text[1001][1001];
symb patt[61];
int next[61];
char found;
int n, m;

void build_next() {
    int i;
    next[0] = -1;
    for (i = 0; i < m; i++) {
        next[i+1] = next[i]+1;
        while (next[i+1] > 0 && patt[i] != patt[next[i+1]-1])
            next[i+1] = next[next[i+1]-1]+1;
    }
}

void kmp(int k) {
    int i, j = 0;
    for (i = 0; i < n; i++)
    while (1) {
        if (text[i][k] == patt[j]) {
            j++;
            if (j == m) {
                printf("%d %d\n", i-j+1, k);
                j = next[j]; if (!found) found = 1;
            }
            break;
        } else if (j == 0) break;
        else j = next[j];
    }
}


int main() {
    symb mask, num;
    int i, j;
    int c = 1;
    char str[1001];

    while (scanf("%d %d ", &n, &m) != EOF) {

        mask = 1; for (i = 1; i < m; i++) mask = (mask<<1) | 1;

        for (i = 0; i < n; i++) {
            num = 0; gets(str);
            for (j = 0; j < m; j++) {
                if (str[j] == '|') num = (num<<1)|1;
                else num <<= 1;
            }
            text[i][0] = num;
            for (; j < n; j++) {
                if (str[j] == '|') num = ((num<<1)|1)&mask;
                else num = (num<<1)&mask;
                text[i][j-m+1] = num;
            }
        }

        for (i = 0; i < m; i++) {
            num = 0; gets(str);
            for (j = 0; j < m; j++) {
                if (str[j] == '|') num = (num<<1)|1;
                else num <<= 1;
            }
            patt[i] = num;
        }

        /* Constroi a tabela next. */
        build_next();

        printf("Instancia %d\n", c++);
        found = 0;
        for (j = 0; j < n-m+1; j++) kmp(j);

        if (!found) puts("nenhuma ocorrencia");

        putchar('\n');
    }

    return 0;
}
