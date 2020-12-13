#include <stdio.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}

int sins[300];
int used[100000];

int main() {
    int i, j, k, n, g;
    n = get_int();
    while (n--) {
        g = get_int();
        for (i = 0; i < g; i++) sins[i] = get_int();
        for (k = 1, used[0] = 0; ;k++) {
            for (i = 0; i < g; i++) {
                j=sins[i]%k;
                if (!(used[j]-k)) { used[k] = 0; break; }
                else used[j] = k;
            }
            if (i==g) break;
        }
        printf("%d\n", k);
    }
}
