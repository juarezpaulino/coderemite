/* Edit Step Ladders */

#include <stdio.h>

typedef char bool;
#define TRUE 1
#define FALSE 0

#define MAXWORDS 25000
#define MAXV MAXWORDS
#define MAXDEGREE 25
#define LENGTH 17

typedef struct {
    char word[LENGTH];
    unsigned short pos;
} words;

typedef struct {
    unsigned short edges[MAXV][MAXDEGREE];
    unsigned short degree[MAXV];
    int nvertices;
} graph;

struct {
    words dict[LENGTH][MAXWORDS];
    short int degrees[LENGTH];
} dic;

/* Global Variables Declaration */
short int maxwords[MAXV];
short int longest;
graph g;

bool is_editstep(const char *a, const char *b) {
    
    int i, diff;
    bool a_c, b_c;
    
    a_c = b_c = FALSE;
    for (i = 0, diff = 0; (a[i+a_c] != '\0') && (b[i+b_c] != '\0'); i++)
        if (a[i+a_c] != b[i+b_c]) {
            diff++;
            if ((diff == 1) && (a[i+1] != b[i+1])) {
                if (a[i+1] == b[i])
                    a_c = TRUE;
                else if (a[i] == b[i+1])
                    b_c = TRUE;
                else return (FALSE);
            }
            if (diff > 1)
                return FALSE;
        }
    if (a_c || b_c) {
        if (a[i+a_c] == b[i+b_c])
            return (TRUE);
        return (FALSE);
    }
    
    if (diff == 1) {
        if (a[i] == b[i])
            return (TRUE);
        return(FALSE);
    }
    else {
        if (a[i] == b[i])
            return (FALSE);
        if ((a[i] == '\0') && (b[i+1] == '\0'))
            return (TRUE);
        if ((a[i+1] == '\0') && (b[i] == '\0'))
            return (TRUE);
        return (FALSE);
    }
}

void read_dictionary(int *nwords) {
    
    int i;
    char ch, aux[LENGTH];
    
    for (i = 1; i < LENGTH; i++)
        dic.degrees[i] = 0;
    
    *nwords = 0;
    i = 0;
    while (ch = getchar()) {
        if (ch == EOF)
            break;
        if (ch == '\n') {
            if (i == 0)
                break;
            aux[i] = '\0';
            strcpy(dic.dict[i][dic.degrees[i]].word, aux);
            dic.dict[i][dic.degrees[i]].pos = *nwords;
            (dic.degrees[i])++;
            (*nwords)++;
            i = 0;
        }
        else {
            aux[i] = ch;
            i++;
        }
    }
}

void construct_graph(graph *g, int nwords) {
    
    int i, j, k;
    
    for (i=0; i < g->nvertices; i++) g->degree[i] = 0;
    
    for (i = 1; i < LENGTH; i++) {
        for (j = 0; j < dic.degrees[i]; j++) {
            if ((i == 7) && (j > 1800))
                return;
            if (i > 1)
                for (k = 0; k < dic.degrees[i-1]; k++)
                    if (dic.dict[i][j].pos < dic.dict[i-1][k].pos)
                        if (is_editstep(dic.dict[i][j].word, dic.dict[i-1][k].word)) {
                            g -> edges[dic.dict[i][j].pos][g -> degree[dic.dict[i][j].pos]] = dic.dict[i-1][k].pos;
                            (g -> degree[dic.dict[i][j].pos])++;
                        }
            if (i < LENGTH - 1)
                for (k = 0; k < dic.degrees[i+1]; k++)
                    if (dic.dict[i][j].pos < dic.dict[i+1][k].pos)
                        if (is_editstep(dic.dict[i][j].word, dic.dict[i+1][k].word)) {
                            g -> edges[dic.dict[i][j].pos][g -> degree[dic.dict[i][j].pos]] = dic.dict[i+1][k].pos;
                            (g -> degree[dic.dict[i][j].pos])++;
                        }
            for (k = j+1; k < dic.degrees[i]; k++)
                if (is_editstep(dic.dict[i][j].word, dic.dict[i][k].word)) {
                    g -> edges[dic.dict[i][j].pos][g -> degree[dic.dict[i][j].pos]] = dic.dict[i][k].pos;
                    (g -> degree[dic.dict[i][j].pos])++;
                }
        }
    }
}

void dfs(graph *g, int v, int *count) {

    int i;
    int y;
    int c;
    
    maxwords[v] = 0;
    
    for (i = 0; i < g->degree[v]; i++) {
        y = g -> edges[v][i];
        if (maxwords[y] == -1) {
            c = 0;
            dfs(g, y, &c);
        }
        else
            c = maxwords[y] + 1;
        if (c > maxwords[v])
            maxwords[v] = c;
    }
    (*count) += (maxwords[v] + 1);
} 

void connected_components(graph *g) {
    
    int i, count;
    
    for (i=0; i < g->nvertices; i++) maxwords[i] = -1;
    longest  = 0;
    
    for (i = 0; i < g->nvertices; i++)
        if (maxwords[i] == -1) {
            count = 0;
            dfs(g, i, &count);
            if (count > longest)
                longest = count;
        }
}


int main() {

    int nwords;
    
    read_dictionary(&nwords);
    g.nvertices = nwords;
    construct_graph(&g, nwords);
    connected_components(&g);
    printf("%hd\n", longest);   

    return 0;
}
