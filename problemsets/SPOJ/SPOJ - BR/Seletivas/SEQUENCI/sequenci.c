#include <stdio.h>
#include <string.h>

int num[300000], d, k;
char in[300000];


int main() {
    
    int i, j, f, ki, c = 1;
    
    while (scanf("%d", &d) != EOF) {
        memset(in, 0, sizeof(in));
        scanf("%d", &num[0]); scanf("%d", &num[1]);
        if (num[1] <= num[0]) f = 1; else f = 0;
        k = d; num[k] = num[0]+num[1]; in[num[k++]] = 1;
        for (i = 2; i < d; i++) {
            scanf("%d", &num[i]); if (in[num[i]]) f = 1;
            if (num[i] <= num[i-1]) f = 1;
            if (!f) {
                ki = k;
                for (j = 0; j < i; j++) {
                    num[k] = num[i]+num[j]; if (!in[num[k]]) in[num[k++]] = 1;
                }
                for (j = d; j < ki; j++) {
                    num[k] = num[i]+num[j]; if (!in[num[k]]) in[num[k++]] = 1;
                }
            }
        }
        printf("Case #%d:", c++); for (i = 0; i < d; i++) printf(" %d", num[i]); putchar('\n');
        if (f) puts("This is not an A-sequence.");
        else puts("This is an A-sequence.");
    }
    
    return 0;
}
