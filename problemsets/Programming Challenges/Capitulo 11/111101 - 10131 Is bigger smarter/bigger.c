/* Is bigger smarter? */

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 1000

typedef struct {
    int w;
    int iq;
    int original;
} elephant;


int dec_compare(const void *x, const void *y) {

    elephant *a = (elephant *)x;
    elephant *b = (elephant *)y;

    if (a->iq != b->iq)
        return (b->iq - a->iq);
    return (b->w - a->w);
}

int binary_search(int a[], int key, int start, int end) {
    
    int pos;
    
    if (start > end)
            return (start);
    pos = (start+end)/2;
    if (a[pos] == key)
        return (-1);
    else if (a[pos] > key)
        return (binary_search(a, key, start, pos-1));
    else
        return (binary_search(a, key, pos+1, end));
}

int LIS(elephant n[], int nelephants, int parent[], int *last) {
    
    int i, pos, length;
    int a[MAXLEN];
    int position[MAXLEN];
    
    length = 0;
    parent[0] = -1;
    a[0] = -1;
    position[0] = 0;
    for (i = 1; i < nelephants; i++) {
        pos = binary_search(a, n[i].w, 0, length);
        if (pos > length) {
            length = pos;
            *last = i;
        }
        a[pos] = n[i].w;
        position[pos] = i;
        parent[i] = position[pos-1];
    }
    
    return (length);
}

void reconstruct_path(elephant n[], int parent[], int last) {
    
    if (parent[last] == -1) return;
    
    reconstruct_path(n, parent, parent[last]);
    printf("%d\n", n[last].original);
}


int main() {

    elephant n[MAXLEN];
    int parent[MAXLEN];
    int w, iq;
    int i, size, last;
    
    n[0].w = -1;
    n[0].iq = -1;
    n[0].original = -1;
    i = 1;
    while (scanf("%d %d", &w, &iq) != EOF) {
        
        n[i].w = w;
        n[i].iq = iq;
        n[i].original = i;
        
        i++;
    }
    
    qsort(&n[1], i-1, sizeof(elephant), dec_compare);
    
    size = LIS(n, i, parent, &last);
    printf("%d\n", size);
    reconstruct_path(n, parent, last);
    
    return 0;
}
