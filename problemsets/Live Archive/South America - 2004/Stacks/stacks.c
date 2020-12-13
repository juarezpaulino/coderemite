/* Two-Stacks Solitaire */

#include <stdio.h>

#define MAXC 208

typedef char bool;
#define TRUE 1
#define FALSE 0

#define min(a, b) ((a)<(b)?(a):(b))

typedef struct {
    int s[MAXC];
    int top;
} stack;

typedef struct {
    int edge[MAXC][MAXC];
    int degree[MAXC];
} graph;

graph g;
char destiny[MAXC];
int min[MAXC];
int value[MAXC];
stack inter[2];
int n;

void init_stk(stack *s) {
    s->top = 0;    
}

bool empty(stack *s) {
    return (s->top == 0);
}

int top(stack *s) {
    return (s->s[s->top-1]);
}

void push(stack *s, int num) {
    s->s[s->top++] = num;
}

void pop(stack *s) {
    --s->top;
}

bool DFS(int v, int num) {
    
    int i;
    int y;
    
    if (destiny[v] != -1) return(destiny[v] == num);
    
    destiny[v] = num;
    for (i = 0; i < g.degree[v]; i++) {
        y = g.edge[v][i];
        if (!DFS(y, num^1)) return (FALSE);
    }
    return (TRUE);
}

bool bipart() {
    
    int i;
    
    for (i = 0; i < n; i++) destiny[i] = -1;
    
    for (i = 0; i < n; i++)
        if (destiny[i] == -1)
            if (!DFS(i, 0)) return (FALSE);
    return (TRUE);
}

void print() {
    
    int i;
    int num;
    
    init_stk(&inter[0]); init_stk(&inter[1]);
    for (i = 0; i < n; i++) {
        num = destiny[i];
        if ((empty(&inter[num])) || (value[i] <= top(&inter[num]))) {
            push(&inter[num], value[i]);
            printf("push %d\n", num+1);
        }
        else {
            while ((!empty(&inter[num])) && (value[i] > top(&inter[num]))) {
                if ((!empty(&inter[num^1])) && (top(&inter[num^1]) < top(&inter[num]))) {
                    pop(&inter[num^1]);
                    printf("pop %d\n", (num^1)+1);
                }
                else {
                    pop(&inter[num]);
                    printf("pop %d\n", num+1);
                }
            }
            push(&inter[num], value[i]);
            printf("push %d\n", num+1);
        }
    }
    
    if (!empty(&inter[0])) num = 0; else num = 1;
    while ((!empty(&inter[0])) && (!empty(&inter[1])))
        if (top(&inter[0]) <= top(&inter[1])) {
            pop(&inter[0]);
            printf("pop 1\n");
            num = 1;
        }
        else {
            pop(&inter[1]);
            printf("pop 2\n");
            num = 0;
        }

    while (!empty(&inter[num])) {
        pop(&inter[num]);
        printf("pop %d\n", num+1);
    }
}


int main() {
    
    int i, j;
    int t;
    
    t = 0;
    while (scanf("%d", &n)) {
    
        if (!n) break;
        t++;
        
        for (i = n-1; i >= 0; i--) scanf("%d", &value[i]);
        
        for (i = 0; i < n; i++) g.degree[i] = 0;
        min[n-1] = 1000;
        for (i = n-2; i >= 0; i--) min[i] = min(value[i+1], min[i+1]);
        
        for (i = 0; i < n-1; i++)
            for (j = i+1; j < n; j++)
                if ((value[i] < value[j]) && (min[j] < value[i])) {
                    g.edge[i][g.degree[i]++] = j;
                    g.edge[j][g.degree[j]++] = i;
                }
        printf("#%d\n", t);
        if (!bipart()) { printf("impossible\n"); continue; }
        
        print();
    }
    
    return 0;
}
