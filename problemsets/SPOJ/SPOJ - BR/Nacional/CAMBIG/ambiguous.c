#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAXW 100
#define MAXL 51
#define MAXH 1013
#define MAXV MAXH
#define MAXINT 0X7FFFFFFF


typedef struct HashKey {
    char str[MAXL];
    int pos;
    struct HashKey *next;
} hashKey;

typedef struct {
    char str[MAXL];
    int s;
} word;


int n;
word dic[MAXW];
hashKey *hash[MAXH];
int nv;

typedef struct {
    int d;          /* distancia do inicio. */
    int h;          /* indice heap. */
    char *str;      /* Conteudo do nodo. */
} vertex;

#define LEFT(i) ((i)<<1)
#define RIGHT(i) (((i)<<1)|1)
#define PAI(i) ((i)>>1)

int H[MAXV];
int heapsize;
vertex vert[MAXV];


void initHash() {
    int i;
    for (i = 0; i < MAXH; i++) hash[i] = NULL;
}

int fKey(char str[]) {
    int i, sum = 0;
    for (i = 0; str[i] != '\0'; i++) sum += ((i+1)*str[i]) + (str[i]<<(i%7));
    return (sum % MAXH);
}

hashKey *insertHash(char str[]) {
    int pos = fKey(str);
    hashKey *pt, *ptaux;
    if (hash[pos] == NULL) {
        hash[pos] = (hashKey *) malloc(sizeof(hashKey));
        strcpy(hash[pos]->str, str);
        hash[pos]->pos = nv;
        hash[pos]->next = NULL;
        vert[nv].d = MAXINT;
        vert[nv].h = 0;
        vert[nv].str = hash[pos]->str;
        nv++;
        return hash[pos];
    }
    pt = hash[pos];
    while (pt != NULL) {
        if (!strcmp(str, pt->str))
            return pt;
        ptaux = pt;
        pt = pt->next;
    }
    pt = (hashKey *) malloc(sizeof(hashKey));
    strcpy(pt->str, str);
    pt->pos = nv;
    pt->next = NULL;
    ptaux->next = pt;
    vert[nv].d = MAXINT;
    vert[nv].h = 0;
    vert[nv].str = pt->str;
    nv++;
    return pt;
}

hashKey *getHash(char str[]) {
    int pos = fKey(str);
    hashKey *pt = hash[pos];
    while (pt) {
        if (!strcmp(str, pt->str))
            return pt;
        pt = pt->next;
    }
    return NULL;
}


/* Dijkstra */
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
    
    int ret = H[1];

    H[1] = H[heapsize--];
    vert[H[1]].h = 1;
    corrige(H, 1);
    return ret;
}

int dijkstra(char str[]) {
    
    int i, j;
    int v;
    hashKey *pt;
    word adj[MAXW];
    int nadj;
    int s;
    
    initHash();
    
    pt = insertHash(str);
    vert[pt->pos].d = 0;
    insertUpdate(H, pt->pos);
    while ( heapsize > 0 ) {
        i = minimum(H);
        s = strlen(vert[i].str);
        vert[i].h = -1;
        nadj = 0;
        #ifdef DEBUG
        printf("Nodo %s %d %d\n", vert[i].str, s, vert[i].d);
        #endif
        for (j = 0; j < n; j++) {
            if (!strcmp(dic[j].str, vert[i].str)) return vert[i].d+dic[j].s;
            else if (dic[j].s < s) {
                if (strstr(vert[i].str, dic[j].str) == vert[i].str) {
                    strcpy(adj[nadj].str, &vert[i].str[dic[j].s]);
                    adj[nadj++].s = dic[j].s;
                    #ifdef DEBUG
                    printf("Adjacency %s %d\n", adj[nadj-1].str, adj[nadj-1].s);
                    #endif
                }
            }
            else if (dic[j].s > s) {
                if (strstr(dic[j].str, vert[i].str) == dic[j].str) {
                    strcpy(adj[nadj].str, &dic[j].str[s]);
                    adj[nadj++].s = s;
                    #ifdef DEBUG
                    printf("Adjacency %s %d\n", adj[nadj-1].str, adj[nadj-1].s);
                    #endif
                }
            }
        }
        for (j = 0; j < nadj; j++) {
            pt = insertHash(adj[j].str);
            v = pt->pos;
            if (vert[v].h >= 0)
                if (vert[v].d > vert[i].d + adj[j].s) {
                    vert[v].d = vert[i].d + adj[j].s;
                    insertUpdate(H, v);
                }
        }
    }
    return -1;
}


int cmp(word *a, word *b) {
    return (a->s-b->s);    
}


int main() {

    int i, j;
    char str[MAXL], *pt;
    int min, aux;
    int cmp();
    
    while (scanf("%d ", &n)) {
        
        if (!n) break;
        
        for (i = 0; i < n; i++) {
            gets(dic[i].str);
            dic[i].s = strlen(dic[i].str);
        }
        qsort(dic, n, sizeof(word), cmp);
        
        #ifdef DEBUG
        printf("Dicionario\n");
        for (i = 0; i < n; i++)
            printf("%s %d\n", dic[i].str, dic[i].s);
        #endif
        
        min = MAXINT;
        for (i = 0; i < n; i++)
            for (j = i+1; j < n; j++) {
                if (dic[i].s == dic[j].s) continue;
                pt = strstr(dic[j].str, dic[i].str);
                if (pt == dic[j].str) {
                    strcpy(str, &dic[j].str[dic[i].s]);
                    heapsize = nv = 0;
                    #ifdef DEBUG
                    printf("Dijkstra %s %d\n", str, strlen(str));
                    #endif
                    aux = dijkstra(str);
                    if (aux >= 0) {
                        if (aux + dic[i].s < min)
                            min = aux + dic[i].s;
                    }
                }
            }
        
        if (min == MAXINT) printf("-1\n");
        else printf("%d\n", min);
    }
    
    return 0;
}
