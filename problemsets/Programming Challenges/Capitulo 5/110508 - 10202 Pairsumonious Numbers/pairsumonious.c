/* Pairsumonious Numbers */

#include <stdio.h>
#include <stdlib.h>

#define MAXSUMS 36
#define MAXN 9

int sum[MAXSUMS];
int nums[MAXN];
int n;
int n_sums;
int fix;
char finished;
char valid_sum[MAXSUMS];

int compare(int *a, int *b) {

    return (*a - *b);
}

int search(char v[], int s) {

    int i;

    for (i = 0; i < n_sums; i++)
        if (v[i])
            if (s == sum[i])
                return i;
    return -1;
}

int valid(char v[], int k) {

    int i;
    int pos;

    for (i = 0; i < k-1; i++) {
        if ((pos = search(v, nums[k-1]+nums[i])) == -1)
            return (0);
        else
            v[pos] = 0;
    }

    return 1;
}

void backtrack(int k) {

    int i;

    if (valid(valid_sum, k)) {
        if (k == n) {finished = 1; return;}
        if (k-1 < fix) {
            nums[k] = sum[k-1]-nums[0];
            backtrack(k+1);
            if (finished) return;
        }
        else
            for (i = fix+1; i < n_sums - (n-k); i++) {
                nums[k] = sum[i] - nums[0];
                backtrack(k+1);
                if (finished) return;
            }
    }
}


int main () {

    int i, j;
    int compare();

    while (scanf("%d", &n) != EOF) {
        n_sums = (n*(n-1))/2;

        for (i = 0; i < n_sums; i++)
            scanf("%d", &sum[i]);
        qsort(sum, i, sizeof(int), compare);

        finished = 0;
        for (i = 2; i < n; i++) {
            valid_sum[0] = 0;
            for (j = 1; j < n_sums; j++)
                valid_sum[j] = 1;
            fix = i;
            nums[0] = (sum[0]+sum[1]-sum[i])/2;
            nums[1] = sum[0]-nums[0];
            nums[2] = sum[1]-nums[0];
            backtrack(3);
            if (finished) break;
        }
        if (finished) {
            for (i = 0; i < n-1; i++)
                printf("%d ", nums[i]);
            printf("%d\n", nums[i]);
        }
        else
            printf("Impossible\n");
    }

    return 0;
}
