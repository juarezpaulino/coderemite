#include <stdio.h>

int coin[20];
int troco[20000];
int fila[1000001], first, last;
int l, r, u;

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}


int main() {

    register int v, y, k;
    register int i, c = 1;
    
    while (1) {
        l = get_int(); u = get_int(); r = get_int();
        if (!l && !u && !r) break;
        for (i = r-1; i >= 0; i--) coin[i] = get_int();
        for (i = 0; i < 10000; i++) troco[i] = 0x7F7F7F7F;
        first = last = 0; fila[last++] = l; troco[l] = 0;
        while (first != last) {
            v = fila[first++]; k = troco[v]+1;
            for (i = 0; i < r; i++) {
                y = (v+coin[i])%10000;
                if (k<troco[y]) {
                    troco[y] = k;
                    if (y==u) goto OUT;
                    fila[last++] = y;
                }
            }
        }
OUT:
        if (troco[u]==0x7F7F7F7F) printf("Case %d: Permanently Locked\n", c++);
        else printf("Case %d: %d\n", c++, troco[u]);
    }
    
    return 0;
}
