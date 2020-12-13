#include <stdio.h>

int get_int() {

    int ch, i, sign;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    if (ch == '-') { sign = 1; ch = getchar(); } else sign = 0;

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    if (sign) return (i * -1);
    return i;
}


int main() {

    int n, s, max;
    int i, j, x;
    int v[15000];
    char sig;
    
    while (n = get_int()) {
        v[0] = get_int(); sig = (v[0] < 0) ? 1 : 0;
        for (i = 1, j = 0; i < n; i++) {
            x = get_int();
            if (x < 0) { 
                if (sig) v[j] += x; 
                else { v[++j] = x; sig = 1; }
            }
            else {
                if (!sig) v[j] += x;
                else { v[++j] = x; sig = 0; }
            }
        }
        
        s = max = 0;
        for (i = 0; i <= j; i++) {
            if (v[i] >= 0) s += v[i];
            else { 
                if (s + v[i] > 0) s += v[i];
                else s = 0;
            }
            if (s > max) max = s;
        }
        
        if (!max) puts("Losing streak.");
        else printf("The maximum winning streak is %d.\n", max);
    }
    
    return 0;
}
