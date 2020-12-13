/* Doublets */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C

#ifdef C
typedef char bool;
#define TRUE 1
#define FALSE 0
#undef C
#endif

#define MAXV 25143
#define MAXDEGREE 30
#define LENGHT 16

typedef char word[LENGHT+1];

typedef struct {
    word words[MAXV];
    int nwords[LENGHT+1];
    int begin[LENGHT+1];
    int end[LENGHT+1];
    int lines;
} dictionary;

typedef struct {
    unsigned short edges[MAXV][MAXDEGREE];
    unsigned short degree[MAXV];
    int nvertices;
} graph;

int compare(const void *x, const void *y) {

    char *a = (char *) x;
    char *b = (char *) y;
    int lena = strlen(a);
    int lenb = strlen(b);
    
    if ((lena - lenb) != 0)
        return (lena - lenb);
    
    return (strcmp(a, b));
}

void read_dictionary(dictionary *dic) {
    
    int i;
    
    dic -> lines = 0;
    for (i = 1; i <= LENGHT; i++) {
        dic -> nwords[i] = 0;
        dic -> begin[i] = -1;
        dic -> end[i] = -1;
    }
    
    while (gets(dic -> words[dic -> lines])) {
        
        if (*(dic -> words[dic -> lines]) == '\0')
            break;
        (dic -> nwords[strlen(dic -> words[dic -> lines])])++;
        (dic -> lines)++;
    }
}   

bool is_doublet(const char *x, const char *y, int len) {

    int i, diff;
    
    for (i = 0, diff = 0; i < len; i++)
        if (x[i] != y[i]) {
            diff++;
            if (diff > 1)
                return (FALSE);
        }
    if (diff == 0)
        return (FALSE);
    return (TRUE);
}

void initialize_graph(graph *g) {
    
    int i;
    
    for (i=0; i<MAXV; i++) g->degree[i] = 0;
}

void insert_edge(graph *g, int x, int y, bool directed) {
    
    g -> edges[x][g->degree[x]] = y;
    g -> degree[x]++;
    
    if (directed == FALSE)
        insert_edge(g, y, x, TRUE);
}

void construct_graph(graph *g, dictionary *dic) {
    
    int i, j, k, pos;
    
    initialize_graph(g);
    g -> nvertices = dic -> lines;
    
    for (i = 1, pos = 0; i <= LENGHT; i++) {
        for (j = 0; j < (dic -> nwords[i]); j++) {
            if (j == 0)
                dic -> begin[i] = pos;
            for (k = j+1; k < (dic -> nwords[i]); k++)
                if (is_doublet(dic -> words[pos + j], dic -> words[pos + k], i))
                    insert_edge(g, pos+j, pos+k, FALSE);
        }
        if (j != 0) {
            pos += j;
            dic -> end[i] = (pos - 1);
        }
    }
}

/* Queue Definition */
typedef struct {
    int q[MAXV+1];
    int first;
    int last;
    int count;
} queue;

void init_queue(queue *q) {
    
    q -> first = 0;
    q -> last = MAXV-1;
    q -> count = 0;
}

void enqueue(queue *q, int x) {
    
    q -> last = (q->last + 1) % MAXV;
    q -> q[q -> last] = x;
    (q -> count)++;
}

int dequeue(queue *q) {
    
    int x;
    
    x = q -> q[q->first];
    q -> first = (q -> first+1) % MAXV; 
    (q -> count)--;

    return (x);
}

bool empty(queue *q) {
    
    if (q -> count <= 0) return TRUE;
    
    return FALSE;
}

/* Breadth-First Search */
bool discovered[MAXV];
int parent[MAXV];

void initialize_search(graph *g) {
    
    int i;
    
    for (i = 0; i < g->nvertices; i++) {
        discovered[i] = FALSE;
        parent[i] = -1;
    }
}

void bfs(graph *g, int start) {

    queue q;
    int v;
    int i;

    initialize_search(g);    
    init_queue(&q);
    enqueue(&q, start);
    discovered[start] = TRUE;
    
    while (empty(&q) == FALSE) {
        v = dequeue(&q);
        for (i = 0; i < g->degree[v]; i++)
            if (discovered[g->edges[v][i]] == FALSE) {
                enqueue(&q, g->edges[v][i]);
                discovered[g->edges[v][i]] = TRUE;
                parent[g->edges[v][i]] = v;
            }
    }
}

int binary_search(word words[], const char *key, int first, int last) {

    int pos, cmp;
    
    if (first > last)
        return -1;
    pos = (first + last)/2;
    cmp = strcmp(key, words[pos]);
    if (cmp == 0)
        return (pos);
    else if (cmp < 0)
        return (binary_search(words, key, first, pos-1));
    return (binary_search(words, key, pos+1, last));
}

void find_path(dictionary *dic, int start, int end, int parents[]) {
    
    if ((start ==  end) || (end == -1))
        printf("%s\n", dic -> words[start]);
    else {
        find_path(dic, start, parents[end], parents);
        printf("%s\n", dic -> words[end]);
    }
}


graph g;

int main() {
    
    dictionary dic;
    char pair[2][50], num;
    int lena, lenb, posinit, posend, i;
    bool print_line;
    
    read_dictionary(&dic);
    qsort(dic.words, dic.lines, sizeof(word), compare);
    construct_graph(&g, &dic);
    print_line = FALSE;
    
    while (scanf("%s %s", pair[0], pair[1]) != EOF) {
        if (print_line == TRUE)
            putchar('\n');
        getchar();
        
        lena = strlen(pair[0]);
        lenb = strlen(pair[1]);
        if (lena != lenb)
            printf("No solution.\n");
        else {
            posinit = binary_search(dic.words, pair[0], dic.begin[lena], dic.end[lena]);
            posend = binary_search(dic.words, pair[1], dic.begin[lenb], dic.end[lenb]);
            if ((posinit == -1) || (posend == -1))
                printf("No solution.\n");
            else if (!strcmp(pair[0], pair[1])) {
                if (g.degree[posinit] != 0) {
                    printf("%s\n", pair[0]);
                    printf("%s\n", dic.words[g.edges[posinit][0]]);
                    printf("%s\n", pair[0]);
                }
                else
                    printf("No solution.\n");
            }
            else {
                bfs(&g, posinit);
                if (parent[posend] == -1)
                    printf("No solution.\n");
                else
                    find_path(&dic, posinit, posend, parent);
            }
        }
        if (print_line == FALSE)
            print_line = TRUE;
    }           
    
    return 0;
}
