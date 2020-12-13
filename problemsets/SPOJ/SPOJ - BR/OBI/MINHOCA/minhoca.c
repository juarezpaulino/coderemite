#include <stdio.h>
int main() {
    int n, m;
    int i, j;
    int s, max;
    int num[100][100];
    
    scanf("%d %d", &n, &m);
    max = 0;
    for (i = 0; i < n; i++) {
        s = 0;
        for (j = 0; j < m; j++) {
            scanf("%d", &num[i][j]);
            s += num[i][j];
        }
        if (s > max) max = s;
    }
    for (j = 0; j < m; j++) {
        s = 0;
        for (i = 0; i < n; i++) s += num[i][j];
        if (s > max) max = s;
    }
    printf("%d\n", max);
    return 0;
}
