/* Light Up */

#include <stdio.h>
#include <stdlib.h>

typedef char bool;
#define TRUE 1
#define FALSE 0

int n, m;
int b, nb;
char fim;
int min;

void back1(int k, int kb, char t[8][8]);
void back2(int k, char t[8][8], int r, int c);

void print(char st[8][8]) {
    
    int i, j;
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++)
            if (st[i][j] == -1) printf("b ");
            else printf("%d ", st[i][j]);
        printf("\n");
    }
}

void copy(char d[8][8], char o[8][8]) {

    int i, j;
    for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) d[i][j] = o[i][j];
}

void zero(char t[8][8], int r, int c) {
    
    if ((r-1 > 0) && (t[r-1][c] == 6)) t[r-1][c] = 7;
    if ((c-1 > 0) && (t[r][c-1] == 6)) t[r][c-1] = 7;
    if ((r+1 <= n) && (t[r+1][c] == 6)) t[r+1][c] = 7;
    if ((c+1 <= m) && (t[r][c+1] == 6)) t[r][c+1] = 7;
    t[r][c] = -1;
}

void reduce(char t[8][8], int r, int c, int *kb) {
    
    if ((r-1 > 0) && (t[r-1][c] > 0) && (t[r-1][c] < 5)) {
        t[r-1][c]--;
        if (t[r-1][c] == 0) { zero(t, r-1, c); *kb = *kb+1; }
    }
    if ((c-1 > 0) && (t[r][c-1] > 0) && (t[r][c-1] < 5)) {
        t[r][c-1]--;
        if (t[r][c-1] == 0) { zero(t, r, c-1); *kb = *kb+1; }
    }
    if ((r+1 <= n) && (t[r+1][c] > 0) && (t[r+1][c] < 5)) {
        t[r+1][c]--;
        if (t[r+1][c] == 0) { zero(t, r+1, c); *kb = *kb+1; }
    }
    if ((c+1 <= m) && (t[r][c+1] > 0) && (t[r][c+1] < 5)) {
        t[r][c+1]--;
        if (t[r][c+1] == 0) { zero(t, r, c+1); *kb = *kb+1; }
    }
}

bool legal(char t[8][8], int r, int c) {
    
    if ((r < 1)||(c < 1)||(r > n)||(c > m)||(t[r][c] != 6)) return(FALSE);
    return (TRUE);
}

bool lm(char t[8][8], int r, int c) {
    
    if ((r < 1)||(c < 1)||(r > n)||(c > m)||(t[r][c] < 5)) return(FALSE);
    return (TRUE);
}

void move(char t[8][8], int r, int c) {

    int i;    
    
    for (i = r; lm(t, i, c); i--) t[i][c] = 5;
    for (i = c-1; lm(t, r, i); i--) t[r][i] = 5;
    for (i = r+1; lm(t, i, c); i++) t[i][c] = 5;
    for (i = c+1; lm(t, r, i); i++) t[r][i] = 5;
}

int is_solution(char st[][8]) {
    
    int i, j;
    
    for (i = 1; i <= n; i++) 
        for (j = 1; j <= m; j++) 
            if (st[i][j] > 5) return (0);
    return (1);
}

void perm(char t[8][8], int last, int k, int kb, int pk, int np, int r, int c) {

    int i;
    int ikb;
    bool p[4];
    char st[8][8];
    
    if (pk == np) { back1(k, kb, t); return; }
    
    for (i = last+1; i <= (last+1)+4-np+pk; i++)
        if ((i == 0) && (legal(t, r-1, c))) {
            copy(st, t);
            ikb = kb;
            move(st, r-1, c);
            reduce(st, r-1, c, &ikb);
            perm(st, 0, k+1, ikb, pk+1, np, r, c);
        }
        else if ((i == 1) && (legal(t, r, c-1))) {
            copy(st, t);
            ikb = kb;
            move(st, r, c-1);
            reduce(st, r, c-1, &ikb);
            perm(st, 1, k+1, ikb, pk+1, np, r, c);
        }
        else if ((i == 2) && (legal(t, r+1, c))) {
            copy(st, t);
            ikb = kb;
            move(st, r+1, c);
            reduce(st, r+1, c, &ikb);
            perm(st, 2, k+1, ikb, pk+1, np, r, c);
        }
        else if ((i == 3) && (legal(t, r, c+1))) {
            copy(st, t);
            ikb = kb;
            move(st, r, c+1);
            reduce(st, r, c+1, &ikb);
            perm(st, 3, k+1, ikb, pk+1, np, r, c);
        }
}

void back1(int k, int kb, char t[8][8]) {
    
    int i, j;
    char inp[4];
    
    if (kb == nb) { back2(k, t, 1, 0); return; }
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) 
            if ((t[i][j] > 0) && (t[i][j] < 5)) break;
        if (j <= m) break;
    }
    
    if (j <= m) perm(t, -1, k, kb, 0, t[i][j], i, j);
}

void back2(int k, char t[8][8], int r, int c) {

    int i, j;
    char st[8][8];
    int s, u, v;
    bool in[8];

    if (is_solution(t)) { 
        if (k < min) min = k; 
        fim = TRUE; 
        return;
    }
    
    for (i = 1; i <= m; i++) in[i] = FALSE; s = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if ((in[j] == FALSE) && (t[i][j] == 6)) {
                s++;
                in[j] = TRUE;
                break;
            }
    if (k+s >= min) return;
    
    for (i = 1; i <= n; i++) in[i] = FALSE; s = 0;
    for (j = 1; j <= m; j++)
        for (i = 1; i <= n; i++)
            if ((in[i] == FALSE) && (t[i][j] == 6)) {
                s++;
                in[i] = TRUE;
                break;
            }
    if (k+s >= min) return;    
    
    for (i = 1; i <= r; i++) {
        s = (i==r)?c-1:m;
        for (j = 1; j <= s; j++)
            if (t[i][j] == 6) {
                u = (j > c)?r:r+1;
                for (v = u; (v <= n) && (t[v][j] != -1); v++)
                    if (t[v][j] == 6) break;
                if ((v > n) || (t[v][j] == -1)) return;
            }
    }
        
    
    v = FALSE;
    for (i = r; i <= n; i++) {
        for (j = c+1; j <= m; j++) {
            if (legal(t, i, j)) {
                copy(st, t);
                move(st, i, j);
                back2(k+1, st, i, j);
                v = TRUE;
            }
            else if ((v == TRUE) && (st[i][j] == -1)) {
                back2(k, t, i, j);
                return;
            }
        }
        c = 0;
    }
}


int main() {
    
    int i, j;
    char st[8][8];
    int r, c, s;
    
    while (scanf("%d %d", &n, &m)) {
    
        if ((!n) && (!m)) break;    
      
        scanf("%d", &b);
        for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) st[i][j] = 6;
        nb = 0;
        for (i = 0; i < b; i++) {
            scanf("%d %d %d", &r, &c, &s);
            if (s == 0) zero(st, r, c);
            else if (s == -1) st[r][c] = -1;
            else {
                nb++;
                st[r][c] = s;
            }
        }
        
        min = 1000000000;
        fim = FALSE;
        back1(0, 0, st);
        if (!fim) printf("No solution\n");
        else printf("%d\n", min);
    }
    
    return 0;
}
