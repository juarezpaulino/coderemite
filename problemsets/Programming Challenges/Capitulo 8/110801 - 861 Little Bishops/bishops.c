/* Little Bishops */

#include <stdio.h>

#define MAX_CANDIDATES 50

double solution_count;

void backtrack(int *a, int k, int n, int num, int row);
void construct_candidates(int *a, int k, int n, int *c, int *ncandidates, 
int num, int row);

void backtrack(int *a, int k, int n, int num, int row) {
    
    int c[MAX_CANDIDATES];          
    int ncandidates;                
    int i, j;
    
    if (k == num) 
        solution_count++;
    else {
        k++;
        construct_candidates(a, k, n, c, &ncandidates, num, row);
        for (i = 0; i < ncandidates; i++) {
            a[k] = c[i];
            if (k == num)
                backtrack(a, k, n, num, row);
            else
                for (j = row+2; (2*n) - j >= num - k; j+=2)
                    backtrack(a, k, n, num, j);
        }
    }
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates, 
int num, int row) {
    
    int i, j, beg, end;
    char legal_move;

    if (row <= n) {
        beg = n - row + 1;
        end = n + row - 1;
    }
    else {
        beg = row - n + 1;
        end = (3 * n) - row - 1;
    }
    *ncandidates = 0;    
    for (i = beg; i <= end; i+=2) {
        legal_move = 1;
        for (j = 1; j < k; j++)
            if (i == a[j]) {
                legal_move = 0;
                break;
            }
        if (legal_move) {
            c[*ncandidates] = i;
            (*ncandidates)++;
        }
    }
}

void nbishops(int n, int num) {
    
    int a[MAX_CANDIDATES], i, j;
    double black_count, white_count;
    double total;

    if (num == 0) {
        printf("1\n");
        return;
    }
    if (num == 1) {
        printf("%d\n", n*n);
        return;
    }
    if (num >= (2*n) - 1) {
        printf("0\n");
        return;
    }
    
    total = 0;
    for (i = 0; i <= num; i++) {
        
        black_count = 0;
        if (i == 0)
            black_count = 1;
        else 
            for (j = 1; j < (2*n); j+=2) {
                solution_count = 0;
                a[0] = 0;
                backtrack(a, 0, n, i, j);
                black_count += solution_count;
            }
        
        white_count = 0;
        if (num - i == 0)
            white_count = 1;
        else 
            for (j = 2; j < (2*n); j+=2) {    
                solution_count = 0;
                a[0] = 0;
                backtrack(a, 0, n, num - i, j);
                white_count += solution_count;
            }
        
        total += black_count * white_count;
    }
    
    printf("%.0lf\n", total);
}

int main() {
    
    int n, num;
    
    while (scanf("%d %d", &n, &num)) {

        if ((n == 0) && (num == 0))
            break;
        
        nbishops(n, num);
    }
    
    return 0;
}


