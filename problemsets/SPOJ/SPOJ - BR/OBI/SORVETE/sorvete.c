#include <stdio.h>

int soru[10001], sorv[10001];
int ord[10001];

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}

int cmp(int *a, int *b) {
    if (soru[*a] != soru[*b]) return soru[*a]-soru[*b];
}


int main() {

    int p, s;
    register int i, j, u, v, k = 1;
    int cmp();

    while (1) {
        p = get_int(); s = get_int(); if (!p && !s) break;
        for (i = 0; i < s; i++) { 
            ord[i] = i; soru[i] = get_int(); sorv[i] = get_int();
        }
        qsort(ord, s, sizeof(int), cmp);
        printf("Teste %d\n", k++);
        u = soru[ord[0]]; v = sorv[ord[0]];
        for (i = 1; i < s; i++) {
            if (soru[ord[i]] > v) {
                printf("%d %d\n", u, v); u = soru[ord[i]]; v = sorv[ord[i]];
            }
            else if (sorv[ord[i]] > v) v = sorv[ord[i]];
        }
        printf("%d %d\n\n", u, v);
    }
    
    return 0;
}

