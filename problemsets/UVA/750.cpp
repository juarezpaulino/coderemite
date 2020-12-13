/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

int col[10];
int r, c, id;

void go(int j) {
    if (j == 9) {
        printf("%2d     ", id++);
        for (int j = 1; j <= 8; j++) printf(" %d", col[j]);
        putchar('\n');
        return;
    }
    if (j == c) { go(j+1); return; }
    for (int i = 1; i <= 8; i++) {
        bool ok = i != r && i-r != j-c && i-r != c-j;
        for (int k = 1; k < j && ok; k++) {
            if (col[k]==i) ok = 0;
            if (col[k]-i==k-j) ok = 0;
            if (col[k]-i==j-k) ok = 0;
        }
        if (!ok) continue;
        col[j] = i;
        go(j+1);
        col[j] = 0;
    }
}


int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &r, &c);
        memset(col,0,sizeof(col));
        col[c] = r;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        id = 1;
        go(1);
        if (t < T) putchar('\n');
    }

    return 0;
}

