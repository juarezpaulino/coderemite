#include <stdio.h>
#include <stdlib.h>

#define MAXV 100


typedef struct {
    int a, sh, ch, r;
    int cmp;
    int ord;
} student;


student hist[MAXV];
int n;
int in, a, sh, ch, r;


int cmp(student *a, student *b) {
    
    if (a->cmp != b->cmp) return (a->cmp-b->cmp);
    return (a->ord-b->ord);
}


int main() {
    
    int i;
    char cr;
    int k, num;
    char aux[100];
    char blank;
    int cmp();
    
    n = 0;
    while ((cr = getchar()) != '\n') {
        ungetc(cr, stdin);
        scanf("%d %d %d %d %d", &in, &a, &sh, &ch, &r);
        gets(aux);
        hist[n].ord = n;
        hist[n].a = a; hist[n].sh = sh; hist[n].ch = ch;
        hist[n].r = r;
        n++;
    }
    
    blank = 0;
    while ((cr = getchar()) != EOF) {
        ungetc(cr, stdin);
        if (scanf("%d", &k) == EOF) break;
        gets(aux);
        while ((cr = getchar()) != '\n') {
            if (cr == EOF) break;
            ungetc(cr, stdin);
            scanf("%d %d %d %d", &in, &a, &sh, &ch);
            gets(aux);
            if (blank) putchar('\n');
            printf("%d ", in);
            
            for (i = 0; i < n; i++) 
                hist[i].cmp = abs(hist[i].a-a) + abs(hist[i].sh-sh) + abs(hist[i].ch-ch);
            
            qsort(hist, n, sizeof(student), cmp);
            
            num = 0;
            for (i = 0; i < k; i++) num += hist[i].r;
            
            if (num > (k>>1)) putchar('1');
            else putchar('0');
            
            if (!blank) blank = 1;
        }
    }
        
    return 0;
}
