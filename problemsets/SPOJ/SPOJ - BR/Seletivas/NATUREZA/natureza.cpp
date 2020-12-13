/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <map>
#include <string>

#define MAXSET 5001

using namespace std;

map<string, int> m;

struct uf_set { int parent, rank; };

uf_set set[MAXSET];

void make_set(int x) { set[x].parent = x; set[x].rank = 1; }

int find_set(int x) {
     if (set[x].parent == x) return x;
     else { set[x].parent = find_set(set[x].parent); return set[x].parent; }
}
 
void union_set(int x, int y) {
    int xr = find_set(x);
    int yr = find_set(y);
    if (xr != yr) {
        if (set[xr].rank >= set[yr].rank) { set[yr].parent = set[xr].parent; set[xr].rank += set[yr].rank; }
        else { set[xr].parent = set[yr].parent; set[yr].rank += set[xr].rank; }
    }
}



int main() {
    char a[40], b[40];
    int c, r;
    int i, x, y, max;
    while (scanf("%d %d ", &c, &r)) {
        if (!c && !r) break;
        m.clear();
        for (i = 1; i <= c; i++) { scanf("%s ", a); m[a] = i; make_set(i); }
        for (i = 0; i < r; i++) { scanf("%s %s ", a, b); x = m[a]; y = m[b]; union_set(x, y); }
        max = 0;
        for (i = 1; i <= c; i++) {
            x = set[find_set(i)].rank;
            if (x > max) max = x;
        }
        printf("%d\n", max);
    }
    
    return 0;
}
