/*
 * Two Stacks solitaire corrector
 *
 * Juarez Paulino
 * $ Date: 08/14/2007
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXC 208
#define INF 1000000000

#define MIN(a, b) ((a)<(b)?(a):(b))

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
int order[MAXC];
int n;
int n_value, n_order;
int test;
FILE *output;

void init_stk(stack *s) {
    s->top = 0;    
}

int empty(stack *s) {
    return (s->top == 0);
}

int top(stack *s) {
    return (s->s[s->top-1]);
}

void push(stack *s, int num) {
    s->s[s->top++] = num;
}

int pop(stack *s) {
    int num;
    num = s->s[--s->top];
    return (num);
}

int DFS(int v, int num) {
    
    int i;
    int y;
    
    if (destiny[v] != -1) return(destiny[v] == num);
    
    destiny[v] = num;
    for (i = 0; i < g.degree[v]; i++) {
        y = g.edge[v][i];
        if (!DFS(y, num^1)) return (0);
    }
    return (1);
}

int bipart() {
    
    int i;
    
    for (i = 0; i < n; i++) destiny[i] = -1;
    
    /* Check if some of the components contradict. */
    for (i = 0; i < n; i++)
        if (destiny[i] == -1)
            if (!DFS(i, 0)) return (0);
    return (1);
}

void usage() {
    printf("Usage: stacks_corrector input_file output_file\n\n");
    exit(1);    
}

void wrong() {
    printf("WRONG ANSWER\n");
    exit(1);
}

void RTE() {
    printf("Run Time Error\n");
    exit(1);
}

void move(char *op, int num) {
    
    if ((num != 1) && (num != 2)) wrong();
    
    /* Just execute the operations given. */
    if (!strcmp(op, "push")) {
        if (n_value >= n)
            RTE();
        if (inter[num-1].top >= MAXC) RTE();
        push(&inter[num-1], value[n_value++]);
    }
    else if (!strcmp(op, "pop")) {
        if (empty(&inter[num-1]))
            RTE();
        order[n_order++] = pop(&inter[num-1]);
    }
    else
        wrong();
}

void check() {

    int i;
    /* Check for non decreasing order. */
    for (i = 0; i < n-1; i++)
        if (order[i] > order[i+1])
            wrong();
}


int main(int argc, char *argv[]) {
    
    int i, j;
    int intval;
    char strval[10000];
    int impossible;
    
    if (argc != 3) usage();
    
    if (freopen(argv[1], "r", stdin) == NULL) {
        printf("Error: failed to open input file %s\n\n", argv[1]);
        usage();
    }
    
    if ((output = fopen(argv[2], "r")) == NULL) {
        printf("Error: failed to open output file %s\n\n", argv[2]);
        usage();
    }
    
    test = 0;
    while ((scanf("%d", &n) != EOF) && (n > 0)) {
        test++;
        
        for (i = n-1; i >= 0; i--) scanf("%d", &value[i]);
        
        if ((fscanf(output, " #%d", &intval) != 1) || (intval != test))
            wrong();

        if (fscanf(output, "%s", strval) != 1) 
            wrong();

        /* Connect conflict graph */
        for (i = 0; i < n; i++) g.degree[i] = 0;
        min[n-1] = INF;
        for (i = n-2; i >= 0; i--) min[i] = MIN(value[i+1], min[i+1]);
        
        for (i = 0; i < n-1; i++)
            for (j = i+1; j < n; j++)
                if ((value[i] < value[j]) && (min[j] < value[i])) {
                    g.edge[i][g.degree[i]++] = j;
                    g.edge[j][g.degree[j]++] = i;
                }
        /* Check for bipartite */
        impossible = !bipart();
        
        if (!strcmp(strval, "impossible")) {
            if (!impossible)
                wrong();
        }
        else {
            if (fscanf(output, "%d", &intval) != 1)
	           wrong();
        
            n_value = n_order = 0;
            init_stk(&inter[0]); init_stk(&inter[1]);
            
            move(strval, intval);
            for (i = 1; i < 2*n; i++) {
    	       if (fscanf(output, "%s %d", strval, &intval) != 2)
    	           wrong();
    	       move(strval, intval);
            }
            
            /* Check the order of the foundation cards. */
            check();
        }
    }
    
    printf("Accepted\n");
    
    fclose(output);
    return (0);   
}
