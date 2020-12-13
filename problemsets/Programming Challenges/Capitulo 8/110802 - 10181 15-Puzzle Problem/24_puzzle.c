/* 15-Puzzle Problem */

/* Resolve 1000 instancias aleatorias do 15-puzzle problem. */

#include <stdio.h>
#include <stdlib.h>
#include 

#define MAXGRID 4
#define MAXHEURISTIC 2
#define MAXMOVE 60
#define MAXDIR 3

typedef char bool;
#define TRUE 1
#define FALSE 0
#define SOLVED 2

typedef coord[2];
#define X 0
#define Y 1

int is_solvable(int g[][MAXGRID]) {

    int i, j, m, n;
    int sum;
    int start;

    sum = 0;
    for (m = 0; m < MAXGRID; m++)
        for (n = 0; n < MAXGRID; n++)
            if (g[m][n] == 0)
                sum += m;
            else {
                start = (n>0)?n-1:MAXGRID-1;
                for (i = (n>0)?m:m-1; i >= 0; i--) {
                    for (j = start; j >= 0; j--)
                        if (g[m][n] < g[i][j])
                            sum += 1;
                    start = MAXGRID-1;
                }
            }

    if (sum & 1)
        return (TRUE);
    else
        return (FALSE);
}

int is_solution(int g[][MAXGRID]) {

    int i, j;

    for (i = 0; i < MAXGRID; i++)
        for (j = 0; j < MAXGRID; j++)
            if (g[i][j] == 0) {
                if (i*MAXGRID+j != MAXGRID*MAXGRID-1)
                    return (FALSE);
            }
            else {
                if (i*MAXGRID+j != g[i][j]-1)
                    return (FALSE);
            }

    return (TRUE);
}

int is_valid(int g[][MAXGRID], int k, int heur[], int *h, int *count_h) {

    int i, j;
    int sum;

    sum = 0;
    for (i = 0; i < MAXGRID; i++)
        for (j = 0; j < MAXGRID; j++)
            if (g[i][j] != 0) {
                sum += abs(i - ((g[i][j]-1)/MAXGRID));
                sum += abs(j - ((g[i][j]+MAXGRID-1)%MAXGRID));
            }

    if (sum == 0)
        return (SOLVED);

    if (k == 0)
        return (TRUE);

    if (sum + k > MAXMOVE)
        return (FALSE);

    heur[*h] = sum;
    if (heur[*h] > heur[(*h+MAXHEURISTIC-1)%MAXHEURISTIC])
        (*count_h)++;
    else
        *count_h = 0;
    *h = (*h+1)%MAXHEURISTIC;
    if (*count_h > MAXHEURISTIC)
        return (FALSE);
    return (TRUE);
}

void move(int g[][MAXGRID], char dir, coord pos) {

    if (dir == 'U') {
        g[pos[Y]][pos[X]] = g[pos[Y]-1][pos[X]];
        g[pos[Y]-1][pos[X]] = 0;
        pos[Y] = pos[Y]-1;
    }
    else if (dir == 'D') {
        g[pos[Y]][pos[X]] = g[pos[Y]+1][pos[X]];
        g[pos[Y]+1][pos[X]] = 0;
        pos[Y] = pos[Y]+1;
    }
    else if (dir == 'L') {
        g[pos[Y]][pos[X]] = g[pos[Y]][pos[X]-1];
        g[pos[Y]][pos[X]-1] = 0;
        pos[X] = pos[X]-1;
    }
    else {
        g[pos[Y]][pos[X]] = g[pos[Y]][pos[X]+1];
        g[pos[Y]][pos[X]+1] = 0;
        pos[X] = pos[X]+1;
    }
}

void construct_candidates(char c[], int *ncandidates, char solution[], int k, coord pos) {

    int i;

    *ncandidates = 0;
    if (((k == 0) || ((k>0)&&(solution[k-1] != 'D'))) && (pos[Y] > 0)) {
        c[*ncandidates] = 'U';
        (*ncandidates)++;
    }
    if (((k == 0) || ((k>0)&&(solution[k-1] != 'U'))) && (pos[Y] < MAXGRID-1)) {
        c[*ncandidates] = 'D';
        (*ncandidates)++;
    }
    if (((k == 0) || ((k>0)&&(solution[k-1] != 'R'))) && (pos[X] > 0)) {
        c[*ncandidates] = 'L';
        (*ncandidates)++;
    }
    if (((k == 0) || ((k>0)&&(solution[k-1] != 'L'))) && (pos[X] < MAXGRID-1)) {
        c[*ncandidates] = 'R';
        (*ncandidates)++;
    }
}

void move_back(int g[][MAXGRID], char dir, coord pos) {

    if (dir == 'U')
        move(g, 'D', pos);
    else if (dir == 'D')
        move(g, 'U', pos);
    else if (dir == 'R')
        move(g, 'L', pos);
    else
        move(g, 'R', pos);
}

bool finished;
char solution[MAXMOVE+1];

void backtrack(int g[][MAXGRID], char solution[], int k, int heur[], int h, int count_h, coord pos) {

    char c[MAXDIR];
    int ncandidates;
    int s;
    int i,j;

    s = is_valid(g, k, heur, &h, &count_h);
    if (s == SOLVED) {
        solution[k] = '\0';
        finished = TRUE;
    }
    else if (s == TRUE) {
        construct_candidates(c, &ncandidates, solution, k, pos);
        for (i = 0; i < ncandidates; i++) {
            solution[k] = c[i];
            move(g, c[i], pos);
            backtrack(g, solution, k+1, heur, h, count_h, pos);
            if (finished) return;
            move_back(g, c[i], pos);
        }
    }
}


int main() {

    int n;
    int s;
    int grid[MAXGRID][MAXGRID];
    int heur[MAXHEURISTIC];
    int i, j, k, r;
    coord pos;
    char num[MAXGRID*MAXGRID];

    srand(time(NULL));

    s = 0;
    for (i = 0; i < 1000; i++) {
        
        for (j = 0; j < MAXGRID; j++) num[j] = 0;
        
        for (j = 0; j < MAXGRID; j++)
            for (k = 0; k < MAXGRID; k++) {
                while (num[(grid[j][k]] = rand()%16)]);
                num[grid[j][k]] = 1;
                if (grid[j][k] == 0) {
                    pos[X] = k;
                    pos[Y] = j;
                }
            }
        
        finished = FALSE;
        if (is_solvable(grid))
            backtrack(grid, solution, 0, heur, 0, 0, pos);
            if (finished)
                s++;    /* Soma a quantidade de problemas resolvidos. */
        }
    }
    
    printf("%d 15-Puzzles resolvidos.\n", s);
    
    return 0;
}
