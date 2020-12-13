#include <stdio.h>
#include <stdlib.h>

#define MAXV 100


typedef struct {
    int uid;
    int num;
} classe;


int n;
classe cl[MAXV];
int ncl;
int UID[MAXV];
int nUID;
char FID[50][MAXV];
int nFID;


int add_search(int x) {

    int i;
    
    for (i = 0; i < nUID; i++)
        if (UID[i] == x) return i;
    UID[nUID] = x;
    nUID++;
    return (i);
}

void get_classe() {

    int i, j, k;
    char disc[MAXV];
    char adj[MAXV];
    int min;
    
    for (i = 0; i < nUID; i++) disc[i] = 0;
    
    ncl = 0;
    for (i = 0; i < nUID; i++) {
        if (disc[i]) continue;
        
        for (j = 0; j < nUID; j++) adj[j] = 1;
        
        for (j = 0; j < nFID; j++)
            for (k = 0; k < nUID; k++)
                if (FID[j][i] ^ FID[j][k]) adj[k] = 0;
        
        min = UID[i]; k = 0;
        for (j = 0; j < nUID; j++) {
            if (adj[j]) {
                k++;
                if (UID[j] < min) min = UID[j];  
                disc[j] = 1; 
            }
        }
        if (k > 1) { cl[ncl].uid = min; cl[ncl].num = k; ncl++; }
    }
}

int cmp(classe *a, classe *b) {
    
    if (a->num != b->num) return (b->num - a->num);
    
    return (a->uid - b->uid);    
}


int main() {

    int i, j;
    int x, v;
    int c;
    char ch;
    int cmp();

    scanf("%d ", &n);
    for (c = 1; c <= n; c++) {
        printf("Case %d\n", c);
        
        nFID = nUID = 0;
        while (scanf("%d", &x)) {
            if (x == -1) break;
            for (i = 0; i < MAXV; i++) FID[nFID][i] = 0;
            while (1) {
                while (((ch = getchar()) == ' ') || (ch == '\t'));
                if (ch == '\n') break;
                else ungetc(ch, stdin);
                scanf("%d", &x);
                v = add_search(x);
                FID[nFID][v] = 1;
            }
            nFID++;
        }
        
        get_classe();
        
        if (ncl == 0) {
            puts("no prototypes found");
            continue;   
        }
        
        qsort(cl, ncl, sizeof(classe), cmp);
        
        for (i = 0; i < ncl; i++) printf("%d %d\n", cl[i].num, cl[i].uid);
    }

    return 0;
}
