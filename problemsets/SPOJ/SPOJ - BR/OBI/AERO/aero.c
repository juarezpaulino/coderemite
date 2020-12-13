#include <stdio.h>

int aero[101];

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}



int main() {

    int a, v;
    register int i, j, k = 1, m, x, y, s;
    char out[500], str[4];
    while (1) {
        a = get_int(); v = get_int();
        if (!a && !v) break;
        for (i = 1; i <= a; i++) aero[i] = 0;
        for (i = 0; i < v; i++) { x = get_int(); y = get_int(); aero[x]++; aero[y]++; }
        for (i = m = 1; i <= a; i++) m >?= aero[i];
        for (i = 1, j = 0; i <= a; i++) {
            if (aero[i] != m) continue;
            s = i; x = 0;
            if (!s) out[j++] = '0';
            else {
                while (s) { str[x++] = (s%10)+'0'; s/=10; }
                while (x--) out[j++] = str[x];
            }
            out[j++] = ' ';
        }
        out[j-1] = 0;
        printf("Teste %d\n%s\n\n", k++, out);
    }
    
    return 0;
}

