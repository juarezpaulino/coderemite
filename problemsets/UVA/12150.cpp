/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

short final[1000];
char out[8000];
int n, c, p;

int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch == EOF) return (EOF);
    s = (ch == '-') ? 1, ch = getchar() : 0;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    if (s) return -i;
    return i;
}

void print() {
    register int i, j, k, s;
    char str[10];

    for (i = j = 0; i < n; i++) {
        s = final[i]; k = 0;
        if (!s) out[j++] = '0';
        else {
            while (s) { str[k++] = (s%10)+'0'; s/=10; }
            while (k--) out[j++] = str[k];
        }
        if (i < n-1) out[j++] = ' ';
    }
    out[j++] = 0; puts(out);
}

int main() {

    register int i, x;

    while (1) {
        n = get_int();
        if (!n) break;
        for (i = 0; i < n; i++) final[i] = 0;
        for (i = 0; i < n; i++) {
            c = get_int(); p = get_int(); x = i+p;
            if (x < n && x >= 0 && !final[x]) final[x] = c;
            else break;
        }
        if (i < n) puts("-1");
        else print();
        while (++i < n) { get_int(); get_int(); }
    }

    return 0;
}

