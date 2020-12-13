#include <stdio.h>
#include <math.h>


void coord_espiral(int p, int sz, int *x, int *y) {
    int k, v, b;
    if (p == 1) { *x = *y = (sz>>1)+1; return; }
    k = (int)sqrt(p-1)+1; if (!(k&1)) k++; v = k*k; b = (sz>>1)-(k>>1);
    if (p > (v-=k)) { *x = (sz>>1)+(k>>1)+1; *y = b+p-v; return; }
    if (p > (v-=k-1)) { *x = b+p-v; *y = b+1; return; }
    if (p > (v-=k-1)) { *x = b+1; *y = b+k+1-p+v; return; }
    *x = b+2-p+v; *y = (sz>>1)+(k>>1)+1;
}

int get_int() {

    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');

    return i;
}


int main() {
    
    int sz, p, x, y;
    
    while (1) {
        sz = get_int(); p = get_int();
        if (!sz && !p) break;
        coord_espiral(p, sz, &x, &y);
        printf("Line = %d, column = %d.\n", y, x);
    }
    
    return 0;
}
