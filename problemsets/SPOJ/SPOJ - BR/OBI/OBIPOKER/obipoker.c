#include <stdio.h>
#include <stdlib.h>

int cmp(int *a, int *b) { return *a-*b; }

int main() {
    
    int cmp();
    int n, card[5], freq[15], kind[5];
    char st;
    register int k, i, j;
    scanf("%d", &n);
    for (k = 1; k <= n; k++) {
        for (i = 0; i < 5; i++) scanf("%d", &card[i]);
        for (i = 1; i <= 13; i++) freq[i] = 0;
        qsort(card, 5, sizeof(int), cmp);
        for (i = 0, st = 1; i < 5; i++) {
            if (i && card[i] != card[i-1]+1) st = 0;
            freq[card[i]]++; kind[i] = 0;
        }
        if (st) { printf("Teste %d\n%d\n\n", k, card[0]+200); continue; }
        for (i = 1; i <= 13; i++) kind[freq[i]]++;
        if (kind[4]) {
            if (freq[card[0]]==4) i = 0; else i = 1;
            printf("Teste %d\n%d\n\n", k, card[i]+180); continue;
        }
        if (kind[3] && kind[2]) {
            if (freq[card[0]]==3) i = 0; else i = 2;
            printf("Teste %d\n%d\n\n", k, card[i]+160); continue;
        }
        if (kind[3]) {
            if (freq[card[0]]==3) i = 0; else if (freq[card[1]]==3) i = 1; else i = 2;
            printf("Teste %d\n%d\n\n", k, card[i]+140); continue;
        }
        if (kind[2]==2) {
            if (freq[card[0]]==2) { i = 0; if (freq[card[2]]==2) j = 2; else j = 3; }
            else if (freq[card[1]]==2) { i = 1; j = 3; }
            printf("Teste %d\n%d\n\n", k, card[j]*3+card[i]*2+20); continue;
        }
        if (kind[2]) {
            if (freq[card[0]]==2) i = 0; else if (freq[card[1]]==2) i = 1;
            else if (freq[card[2]]==2) i = 2; else i = 3;
            printf("Teste %d\n%d\n\n", k, card[i]); continue;
        }
        printf("Teste %d\n0\n\n", k);
    }
    
    return 0;
}

