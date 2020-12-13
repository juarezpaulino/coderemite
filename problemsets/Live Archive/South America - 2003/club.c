#include <stdio.h>
#include <stdlib.h>

int k;
double r;
int nage[130];

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

int cmp(int *a, int *b) { return (*a-*b); }


int main() {
    
    int i, n;
    double a, b;
    int cmp();
    
    for ( ; k = get_int(), scanf("%lf", &r), k; ) {
        for (i = 0; i < k; i++) nage[i] = get_int(), get_int();
        qsort(nage, k, sizeof(int), cmp);
        for (i = 1, n = 1, b = nage[0]; a = nage[i], i < k; i++) if (a > (b*r+1E-10)) n++, b = nage[i];
        printf("%d\n", n);
    }
    return 0;
}
