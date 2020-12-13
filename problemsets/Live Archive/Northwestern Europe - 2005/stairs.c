#include <stdio.h>
#include <stdlib.h>

int t, N, F, B;
int f[1000]; char b[1000];

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch==EOF) exit(0);
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar()) i = 10 * i + (ch - '0');
    return i;
}

int deliver(unsigned t) {
    int c = 0, i;
    unsigned j;
    for (i = 0; i < N; i++) { j = t; b[i] ? (j-=F-f[i]) : (j+=F-f[i]); c += j/(F<<1); }
    return c;
}


int main() {
    int i, j, c = 0;
    unsigned lo, hi, m;
    t = get_int();
    while (t--) {
        c++;
        N = get_int(); F = get_int(); B = get_int();
        for (i = 0; i < N; i++) f[i] = get_int(), b[i] = get_int();
        lo = 0; hi = F + 2*B*F;
        while (lo < hi-1) { m = (hi+lo)>>1; deliver(m)>=B ? (hi=m) : (lo = m); }
        printf("%d\n", hi);
    }
    
    return 0;
}
