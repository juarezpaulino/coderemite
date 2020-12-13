/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>

#define MAXV 50000

using namespace std;


struct vertex {
    int d;
    vector<int> edges;
    int h;
};


int H[MAXV];
int heapsize;
vertex vert[MAXV];
char inLeague[MAXV];
int h, r;


#define LEFT(i) ((i)<<1)
#define RIGHT(i) (((i)<<1)|1)
#define PAI(i) ((i)>>1)

void insertUpdate(int *H, int v) {

    int i = vert[v].h;

    if (i == 0) i = ++heapsize;
    while ((i > 1) && ((vert[H[PAI(i)]].d > vert[v].d) || 
                      ((vert[H[PAI(i)]].d == vert[v].d) && !inLeague[v] && inLeague[H[PAI(i)]]))) {
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

    if ((l <= heapsize) && ((vert[H[l]].d < vert[H[i]].d) ||
                            ((vert[H[l]].d == vert[H[i]].d) && !inLeague[H[l]] && inLeague[H[i]]))) 
        min = l; 
    else min = i;
    if ((r <= heapsize) && ((vert[H[r]].d < vert[H[min]].d) ||
                            ((vert[H[r]].d == vert[H[min]].d) && !inLeague[H[r]] && inLeague[H[min]])))
        min = r;
    
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

int maxHeap(int *H) {
    
    int i;
    int pow;
    int max;
    
    pow = 0;
    for (i = 0; i < 32; i++) if (heapsize & (1<<i)) pow = i;
    
    max = 0;
    for (i = heapsize; i >= (1<<pow); i--)
        if (vert[H[i]].d > max) max = vert[H[i]].d;
    
    return max;
}



int main() {
    
    int i;
    int a, b;
    int min, max;
    int v, y;
    int nil;
    
    while (scanf("%d %d", &h, &r)) {
    
        if (!h && !r) break;
        
        for (i = 0; i < h; i++) {
            vert[i].edges.clear();
            vert[i].d = 0;
            vert[i].h = 0;
            inLeague[i] = 0;
        }
        
        max = 0;
        for (i = 0; i < r; i++) {
            scanf("%d %d", &a, &b);
            vert[a-1].edges.push_back(b-1);
            vert[a-1].d++;
            if (vert[a-1].d > max) max = vert[a-1].d;
            vert[b-1].edges.push_back(a-1);
            vert[b-1].d++;
            if (vert[b-1].d > max) max = vert[b-1].d;
        }
        
        heapsize = 0;
        nil = 0;
        for (i = 0; i < h; i++)
            if (vert[i].d != 0)
                insertUpdate(H, i);
            else {
                nil++;
                vert[i].h = -1;
            }
        
        v = minimum(H);
        min = vert[v].d;
        while ((min < max) && (!inLeague[v])) {
            vert[v].h = -1;
            nil++;
            for (i = 0; i < vert[v].edges.size(); i++) {
                y = vert[v].edges[i];
                if (vert[y].h != -1) {
                    vert[y].d--;
                    inLeague[y] = 1;
                    insertUpdate(H, y);
                }
            }
            v = minimum(H);
            min = vert[v].d;
            max = maxHeap(H);
        }
        
        for (i = 0; i < h; i++) {
            if (vert[i].h == -1) continue;
            if (vert[i].d != h-nil-1) break;
        }
        if (i != h) printf("N\n");
        else printf("Y\n");
    }
    
    return 0;   
}
