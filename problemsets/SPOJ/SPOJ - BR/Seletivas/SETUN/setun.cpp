/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define FOR(i,n) for((i)=0;(i)<(n);(i)++)


int n;

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch==EOF) exit(0);
    s = (ch=='-')?(ch = getchar(), -1):1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}


int main() {

    int s, i, k;
    char out[100];
    while (1) {
        n = get_int(); if (!n) { puts("0"); continue; }
        s = (n<0) ? (n = -n, -1) : 1;
        for (k = 0; n; )
            out[k++] = (!(n%3)) ? (n = n/3, '0') :
                       ((n%3)==2) ? (n = (n+1)/3, '-') : (n = n/3, '+');
        out[k] = 0;
        if (s<0) FOR(i, k) if (out[i]=='+') out[i]='-'; else if (out[i]=='-') out[i]='+';
        FOR(i, k/2) out[i]^=out[k-1-i]^=out[i]^=out[k-1-i];
        printf("%s\n", out);
    }
    
    return 0;
}

