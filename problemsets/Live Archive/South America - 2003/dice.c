#include <stdio.h>


int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

int p, s;
int t[3];
int pos[11], paused[11];
int n;


int main() {
    
    int i, j, k, l, d1, d2;
    
    for (; p = get_int(), s = get_int(), p+s; ) {
        for (i = 0; i < 3; i++) t[i] = get_int();
        for (i = 0; i < p; i++) pos[i] = 0, paused[i] = 0;
        for (n = get_int(), i = j = 0; i < n; ) {
            if (paused[j]) { paused[j] = 0; j=(j+1)%p; continue; }
            d1 = get_int(); d2 = get_int(); k = d1+d2; i++;
            pos[j]+=k; if (pos[j]>s) break;
            for (l = 0; l < 3; l++) if (t[l]==pos[j]) paused[j] = 1;
            j=(j+1)%p;
        }
        while (i < n) {get_int(); get_int(); i++; }
        printf("%d\n", j+1);
    }
    
    return 0;
}
