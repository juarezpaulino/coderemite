#include <stdio.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}


int main() {

    register int n, max, sp, i, k = 1;
    int cod[1000], med[1000];

    while (1) {
        n = get_int(); if (!n) break;
        printf("Turma %d\n", k++);
        for (i = max = 0; i < n; i++) { 
            cod[i] = get_int(); med[i] = get_int(); if (med[i] > max) max = med[i];
        }
        for (i = sp = 0; i < n; i++) if (med[i] == max) {
            if (sp) putchar(' ');
            printf("%d", cod[i]); sp = 1;
        }
        puts("\n");
    }
    
    return 0;
}


