/* Tug of war */

#include <stdio.h>

int weights[101], total, diff, min;

char finished;

void backtrack(int pos, int sum, int k, int n) {

    int i;

    if (k == n/2) {
        if (abs((2 * sum) - total) < diff) {
            min = sum;
            diff = abs((2 * sum) - total);
        }
        if (diff == 0)
            finished = 1;
    }
    else {
        k++;
        for (i = pos; i <= n + k - (n/2); i++) {
            backtrack(pos + 1, sum + weights[i], k, n);
            if (finished) return;
        }
    }
}

int main() {

    int cases, n, i;
    
    scanf("%d", &cases);
    while (cases) {
    
        scanf("%d", &n);
        total = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d", &weights[i]);
            total += weights[i];
        }
        diff = 8000;
        
        backtrack(1, 0, 0, n);
        if (total - (2*min) > 0)
            printf("%d %d\n", min, total - min);
        else
            printf("%d %d\n", total - min, min);
        
        cases--;
        
        if (cases)
            putchar('\n');
    }   
    
    return 0;
}
