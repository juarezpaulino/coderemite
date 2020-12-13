/* Finding Seats */

#include <stdio.h>

#define INF 0x7fffffff

int r, c, k;
char m[301][301];
int sum[301];
int min;

int main() {
    
    int i, j, l;
    int s, f;
    char ch;
    
    while (scanf("%d %d %d ", &r, &c, &k)) {
        
        if (!r && !c && !k) break;
        
        for (i = 1; i <= r; i++) {
            for (j = 1; j <= c; j++) {
                ch = getchar();
                if (ch == 'X') m[i][j] = 0;
                else m[i][j] = 1;
            }
            getchar();
        }
        
        min = INF;
        for (l = 1; l <= r; l++) {
            for (j = 1; j <= c; j++) sum[j] = 0;
            for (i = l; i <= r; i++) {
                for (j = 1; j <= c; j++) sum[j] += m[i][j];
                s = 0; f = 1;
                for (j = 1; j <= c; j++) {
                    s = s+sum[j];
                    while (s >= k) {
                        if ((i-l+1)*(j-f+1) < min) min = (i-l+1)*(j-f+1);
                        s -= sum[f];
                        f++;
                    }
                }
            }
        }
        
        printf("%d\n", min);
        
    }
    
    return 0;
}
