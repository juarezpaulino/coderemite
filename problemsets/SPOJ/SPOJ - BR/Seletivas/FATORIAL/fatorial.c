#include <stdio.h>


int L[4][5][5] = { 0,6,2,6,4, 2,2,4,2,8, 4,4,8,4,6, 6,6,2,6,4, 8,8,6,8,2,
                   0,2,8,8,4, 2,4,6,6,8, 4,8,2,2,6, 6,2,8,8,4, 8,6,4,4,2,
                   0,4,2,4,4, 2,8,4,8,8, 4,6,8,6,6, 6,4,2,4,4, 8,2,6,2,2,
                   0,8,8,2,4, 2,6,6,4,8, 4,2,2,8,6, 6,8,8,2,4, 8,4,4,6,2
                 };

void ib5(int n, char *num, int *l) {
    int j;
    *l = -1;
    do { j = n%5; num[++*l] = j; } while (n/=5);
}

int lnz(int n) {
    char num[15];
    int k, s = 0;
    if (!n || n==1) return 1;
    ib5(n, num, &k);
    while (k >= 0) s = L[k%4][s>>1][num[k--]];
    return s;
}


int main() {

    int n, k = 1;

    while (scanf("%d", &n) != EOF) {
        printf("Instancia %d\n", k++);
        printf("%d\n\n", lnz(n));
    }

    return 0;
}
