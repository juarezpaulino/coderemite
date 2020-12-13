/* Shortest Pair of Paths */

#include <stdio.h>

typedef struct {
    int v;
    int w;
    char used;
} e;

typedef struct {
    e edge[100][10000];
    int degree[100];
} graph;

graph g;
int n, m;
char used[100];

/* Dijkstra */
typedef struct {
    int d;
    int h;
} vertex;

#define LEFT(i) ((i)<<1)
#define RIGHT(i) (((i)<<1)|1)
#define PAI(i) ((i)>>1)

int H[100];
int heapsize;
vertex vert[100];

void insertUpdate(int *H, int v) {

    int i = vert[v].h;

    if (i == 0) i = ++heapsize;
    while ((i > 1) && (vert[H[PAI(i)]].d > vert[v].d)) {
        H[i] = H[PAI(i)];
        vert[H[PAI(i)]].h = i;
        i = PAI(i);
    }
    H[i] = v;
    vert[v].h = i;
}

void corrige(int *H, int i) {

    int min, aux;
    int l = LEFT(i), r = RIGHT(i);

    if ((l <= heapsize) && (vert[H[l]].d < vert[H[i]].d)) min = l;
    else min = i;
    if ((r <= heapsize) && (vert[H[r]].d < vert[H[min]].d)) min = r;

    if (min != i){
        aux = H[i];
        H[i] = H[min]; vert[H[min]].h = i;
        H[min] = aux; vert[aux].h = min;
        corrige(H, min);
    }
}

int minimum(int *H) {

    int l,r;
    int ret = H[1];

    H[1] = H[heapsize--];
    vert[H[1]].h = 1;
    corrige(H, 1);
    return ret;
}

double dijkstra(int s, int end) {

    int i;
    int j;
    int v;
    int parent[100][2];

    heapsize = 0;
    for( i = 0; i < n+2; i++ ) {
        vert[i].d = 1500000000;
        vert[i].h = 0;
    }

    vert[s].d = 0.0;
    parent[s][0] = -1;
    insertUpdate(H, s);
    while ( heapsize > 0 ) {
        i = minimum(H);
        if (i == end) break;
        vert[i].h = -1;
        for (j = 0; j < g.degree[i]; j++) {
            v = g.edge[i][j].v;
            if ((vert[v].h >= 0) && (!g.edge[i][j].used) && (!used[v]))
                if (vert[v].d > vert[i].d + g.edge[i][j].w) {
                    parent[v][0] = i; parent[v][1] = j;
                    vert[v].d = vert[i].d + g.edge[i][j].w;
                    insertUpdate(H, v);
                }
        }
    }

    if (i != end) return (1500000000);

    j = end;
    while (parent[j][0] != -1) {
        i = parent[j][0];
        if (i != 0) used[i] = 1;
        g.edge[i][parent[j][1]].used = 1;
        j = i;
    }

    return(vert[end].d);
}

int getint() {

    int ch, i, sign = 1;
    while (((ch = getchar()) == ' ') || (ch == '\n'));

    if (ch == EOF) return (EOF);

    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');

    return i;
}


int main() {

    int i;
    int x, y, w;
    int c;

    c = 0;
    while ((n = getint()) != EOF) {
        m = getint();

        if ((!n) && (!m)) break;
        c++;

        for (i = 0; i < n; i++) { g.degree[i] = 0; used[i] = 0; }

        for (i = 0; i < m; i++) {
            x = getint(); y = getint(); w = getint();
            g.edge[x][g.degree[x]].v = y;
            g.edge[x][g.degree[x]].w = w;
            g.edge[x][g.degree[x]++].used = 0;
        }

        printf("Instance #%d: ", c);

        w = dijkstra(0, n-1);
        if (w >= 1500000000) { printf("Not possible\n"); continue; }
        w = w + dijkstra(0, n-1);
        if (w >= 1500000000) { printf("Not possible\n"); continue; }

        printf("%d\n", w);
    }

    return 0;
}
