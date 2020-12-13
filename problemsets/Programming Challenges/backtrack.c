/* Backtracking */

#include <stdio.h>

#define MAX_CANDIDATES 16

char finished;              /* Found all solutions yet? */
int solution_count;
int n;

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates);
void process_solution(int a[], int k);
char is_a_solution(int a[], int k, int n);

void backtrack(int a[], int k, int n) {
    
    int c[MAX_CANDIDATES];          /* Candidates for next position */
    int ncandidates;                /* next position candidate count */
    int i;                          /* Counter */
    
    if (is_a_solution(a, k, n))
        process_solution(a, k);
    else {
        k++;
        construct_candidates(a, k, n, c, &ncandidates);
        for (i = 0; i < ncandidates; i++) {
            a[k] = c[i];
            backtrack(a, k, n);
            if (finished) return;   /* Terminate early */
        }
    }
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates) {
    
    int i, j;                   /* Counters */
    char legal_move;            /* Might the move be legal */
    
    *ncandidates = 0;
    for (i = 1; i <= n; i++) {
        legal_move = 1;
        for (j = 1; j < k; j++) {
            if (abs((k) - j) == abs(i - a[j]))     /* Diagonal threat */
                legal_move = 0;
            if (i == a[j])                          /* Column threat */
                legal_move = 0;
        }
        if (legal_move) {
            c[*ncandidates] = i;
            (*ncandidates)++;
        }
    }
}

void process_solution(int a[], int k) {
    
    solution_count++;
}

char is_a_solution(int a[], int k, int n) {
    
    return (k == n);
}

void nqueens(int n) {
    
    int a[MAX_CANDIDATES];
    
    solution_count = 0;
    backtrack(a, 0, n);
    printf("n=%d solution_count=%d\n", n, solution_count);
}

int main() {
    
    while (scanf("%d", &n)) {
        
        nqueens(n);
    }
    
    return 0;
}
