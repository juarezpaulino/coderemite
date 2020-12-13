/* Is bigger smarter? */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000
#define MATCH 0
#define INSERT 1
#define DELETE 2


typedef struct {
    int cost;
    int parent;
} cell;

typedef struct {
    int weight;
    int iq;
    int original;
} elephant;

cell m[MAXLEN+1][MAXLEN+1];
elephant num[MAXLEN];

void reconstruct_path(elephant num[], int ord[], int i, int j);
void row_init(int i);
void column_init(int i);
int match(int a, int b);
int indel(int a);

int num_compare(elephant num[], int ord[], int size) {
    
    int i, j, k, last;
    int opt[3];
    
    for (i = 0; i < MAXLEN; i++) {
        row_init(i);
        column_init(i);
    }
    
    last = -1;
    for (i = 1; i < size; i++)
        for (j = 1; j < size; j++) {
            opt[MATCH] = m[i-1][j-1].cost + match(num[i].weight, ord[j]);    
            opt[INSERT] = m[i][j-1].cost + indel(ord[j]);
            opt[DELETE] = m[i-1][j].cost + indel(ord[j]);
            
            if (match(num[i].weight, ord[j]) == 1) {
                if (num[i].weight != last) {
                    m[i][j].cost = opt[MATCH];
                    m[i][j].parent = MATCH;
                    last = num[i].weight;
                }
            }
            else if (opt[INSERT] > opt[DELETE]) {
                m[i][j].cost = opt[INSERT];
                m[i][j].parent = INSERT;
            }
            else {
                m[i][j].cost = opt[DELETE];
                m[i][j].parent = DELETE;
            }
        }
    
    return (m[size-1][size-1].cost);
}


void reconstruct_path(elephant num[], int ord[], int i, int j) {

    if (m[i][j].parent == -1) return;
    
    if (m[i][j].parent == MATCH) {
        reconstruct_path(num, ord, i-1, j-1);
        printf("%d\n",num[i].original);
        return;
    }
    if (m[i][j].parent == INSERT) {
        reconstruct_path(num, ord, i, j-1);
        return;
    }
    reconstruct_path(num, ord, i-1, j);
}

void row_init(int i) {

    m[0][i].cost = 0;
    m[0][i].parent = -1;
}

void column_init(int i) {

    m[i][0].cost = 0;
    m[i][0].parent = -1;
}

int match(int a, int b) {

    if (a == b) return (1);
    else return (MAXLEN);
}

int indel(int a) {
    
    return (0);
}

int inc_compare(const void *x, const void *y) {

    int *a = (int *)x;
    int *b = (int *)y;

    return (*a - *b); 
}

int dec_compare(const void *x, const void *y) {

    elephant *a = (elephant *)x;
    elephant *b = (elephant *)y;

    if (a->iq != b->iq)
        return (b->iq - a->iq);
    return (a->weight - b->weight);
}


int main() {

    int ord[MAXLEN];
    int size, w, iq;
    int i;
    
    num[0].weight = ord[0] = 0;
    num[0].iq = 0;
    num[0].original = -1;
    i = 1;
    while (scanf("%d %d", &w, &iq) != EOF) {
        num[i].weight = ord[i] = w;
        num[i].iq = iq;
        num[i].original = i;
        i++;
    }
    qsort(ord, i, sizeof(int), inc_compare);
    qsort(&num[1], i-1, sizeof(elephant), dec_compare);
    
    size = num_compare(num, ord, i);
    printf("%d\n", size);
    
    reconstruct_path(num, ord, i-1, i-1);
      
    return 0;
}

