/* ICPC Strikes again */

#include <stdio.h>

#define MAXT 1001
#define MAXE 1001

typedef char bool;
#define TRUE 1
#define FALSE 0

typedef struct {
    short nd;
    short dep[MAXT];
} task;

typedef struct {
    short nt;
    short t[MAXT];
    bool m[MAXT];
} worker;

int bs[MAXT];
int sig[MAXT];
int pai[MAXT];

worker w[MAXE];
task tsk[MAXT];

int t;
int e;


int calc_sig(int x) {
    
    int i;
    int s;
    
    if (sig[x]) return (sig[x]);
    
    s = bs[x];
    for (i = 0; i < tsk[x].nd; i++)
        if (sig[tsk[x].dep[i]]) s += sig[tsk[x].dep[i]];
        else s += (sig[tsk[x].dep[i]] = calc_sig(tsk[x].dep[i]));
    
    return (s);
}

bool disc[MAXT];

void DFS(int v, int st) {

    int i;
    
    disc[v] = TRUE;
    if (v < st) {
        for (i = 0; i < tsk[v].nd; i++) 
            if (!disc[tsk[v].dep[i]]) {
                tsk[st].dep[tsk[st].nd++] = tsk[v].dep[i];
                disc[tsk[v].dep[i]] = TRUE;
            }
    }
    else {
        for (i = 0; i < tsk[v].nd; i++)
            if (v == st) DFS(tsk[v].dep[i], st);
            else if (!disc[tsk[v].dep[i]]) {
                tsk[st].dep[tsk[st].nd++] = tsk[v].dep[i];
                DFS(tsk[v].dep[i], st);
            }
    }
}

int calc_sal(int x) {
    
    int i, j;
    int s = 0;
    
    for (i = 0; i < w[x].nt; i++)
        if (w[x].m[w[x].t[i]])
            for (j = 0; j < tsk[w[x].t[i]].nd; j++)
                if (w[x].m[tsk[w[x].t[i]].dep[j]])
                    w[x].m[tsk[w[x].t[i]].dep[j]] = FALSE;
    
    for (i = 0; i < w[x].nt; i++) if (w[x].m[w[x].t[i]]) s += sig[w[x].t[i]];
    
    return (s);
}


int main() {
    
    int i, j;
    int nd, ne;
    int x;
    int sal;
    
    while (scanf("%d %d", &t, &e)) {
        
        if ((!t) && (!e)) break;
        
        for (i = 1; i <= e; i++) {
            w[i].nt = 0;
            for (j = 1; j <= t; j++) w[i].m[j] = FALSE;
        }
        
        for (i = 1; i <= t; i++) {
            sig[i] = 0;
            scanf("%d %d %d", &bs[i], &nd, &ne);
            tsk[i].nd = nd;
            for (j = 0; j < nd; j++) {
                scanf("%d", &x);
                tsk[i].dep[j] = x;
            }
            for (j = 0; j < ne; j++) {
                scanf("%d", &x);
                w[x].t[w[x].nt++] = i;
                w[x].m[i] = TRUE;
            }
        }
        
        for (i = 1; i <= t; i++) if (!sig[i]) sig[i] = calc_sig(i);
        
        for (i = 1; i <= t; i++) {
            for (j = 1; j <= t; j++) disc[j] = FALSE;
            for (j = 0; j < tsk[i].nd; j++) disc[tsk[i].dep[j]] = TRUE;
            DFS(i, i);
        }
        
        printf("*****\n");
        for (i = 1; i <= e; i++) {
            printf("%d ", i);
            sal = calc_sal(i);
            printf("%d\n", sal);
        }
    }
    
    return 0;
}
