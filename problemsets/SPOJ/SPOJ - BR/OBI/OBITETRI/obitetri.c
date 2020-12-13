#include <stdio.h>
#include <string.h>

#define INF 0x3F3F3F3F

typedef struct {
    char nome[20];
    int s;
} joga;

joga j[1000];

int cmp(int *a, int *b) { return (*a-*b); }
int cmp2(joga *a, joga *b) {
    if (a->s != b->s) return (b->s-a->s);
    return strcmp(a->nome, b->nome);
}


int main() {
    
    int n, val[12];
    register int i, k = 1, m, p;
    char str[20];
    int cmp(), cmp2();
    while (scanf("%d ", &n) && n) {
        for (i = 0; i < n; i++) {
            gets(j[i].nome);
            for (m = 0; m < 12; m++) scanf("%d ", &val[m]);
            qsort(val, 12, sizeof(int), cmp);
            for (m = 1, j[i].s = 0; m < 11; m++) j[i].s += val[m];
        }
        qsort(j, n, sizeof(joga), cmp2);
        printf("Teste %d\n", k++);
        for (i = 0, p = 1; i < n; i++) {
            if (!i || (i>0 && j[i].s != j[i-1].s)) p = i+1;
            printf("%d %d %s\n", p, j[i].s, j[i].nome);
        }
        putchar('\n');
    }
    
    return 0;
}

