#include <stdio.h>


int main() {

    int x, n, s, i;
    char b[34];
    
    while (scanf("%d", &n)) {
        if (!n) break; x = n; i = 0;
        while (x) { b[i++] = (x&1)+'0'; x>>=1; } b[i] = 0; x = i-1;
        for (i = s = 0; i < x-i; i++) {
            if (b[i]=='1') s++; if (b[x-i]=='1') s++;
            b[i]^=b[x-i]^=b[i]^=b[x-i];
        }
        if (!(x&1) && b[i]=='1') s++;
        printf("The parity of %s is %d (mod 2).\n", b, s);
    }
    
    return 0;
}
