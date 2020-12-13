#include <stdio.h>
#include <stdlib.h>

typedef struct { char let; int freq; } dic;

int cmp(const void *x, const void *y) {
    dic *a = (dic *)x, *b = (dic *)y;
    if (a->freq != b->freq) return (b->freq-a->freq);
    return (a->let-b->let);
}


int main() {
    
    int t, f;
    char cripto[26], orig[27];
    dic tab[26];
    register int i, k = 1;
    char text[10001], str[27];
    while (scanf("%d %d ", &t, &f) && (t||f)) {
        scanf("%s", orig); getchar(); gets(text);
        for (i = 0; i < 26; i++) tab[i].freq = 0, tab[i].let = i;
        for (i = 0; i < t; i++) if (text[i] != ' ') tab[text[i]-'a'].freq++;
        qsort(tab, 26, sizeof(dic), cmp);
        for (i = 0; i < f; i++) cripto[tab[i].let] = orig[i];
        for (i = 0; i < t; i++) if (text[i] != ' ') text[i] = cripto[text[i]-'a'];
        printf("Teste %d\n%s\n\n", k++, text);
    }
    return 0;
}

