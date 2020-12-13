/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <string.h>

int n;
int custo[18][18];
int val[18][1<<18];

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

int pd(int a, int b) {
    if (a == n) return 0;
    if (val[a][b] != -1) return val[a][b];
    int &ret = val[a][b]; ret = 1<<30;
    for(int i = 0; i < n; ++i) if (!(b & 1<<i))
        ret <?= pd(a+1, b|(1<<i))+custo[a][i];
    return ret;
}

int main() {
    
    int i, j, k;
    for (; n = get_int(), n; ) {
        for (i = 0; i < n; i++) for (j = 0; j < n; j++) custo[i][j] = get_int();
        memset(val, -1, sizeof(val));
        printf("%d\n", pd(0,0));
    }
    
    return 0;
}
