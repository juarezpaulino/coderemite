/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <string.h>

int adj[2][2000001][2];
int nadj[2];

struct uf_set { int parent, rank; };

uf_set set[1001];

void make_set(int x) { set[x].parent = x; set[x].rank = 0; }

int find_set(int x) {
     if (set[x].parent == x) return x;
     else { set[x].parent = find_set(set[x].parent); return set[x].parent; }
}

void union_set(int x, int y) {
    int xr = find_set(x);
    int yr = find_set(y);
    if (set[xr].rank > set[yr].rank) set[yr].parent = set[xr].parent;
    else if (set[xr].rank < set[yr].rank) set[xr].parent = set[yr].parent;
    else if (xr != yr) { set[yr].parent = xr; set[xr].rank = set[xr].rank+1; }
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

    int n, m;
    int u, v, w, k;
    int s;
    int c = 1;

    while (1) {
        if ((n = getint()) == EOF) break;
        m = getint();
        
        k = 0;
        for (int i = 1; i <= n; i++) make_set(i);
        nadj[0] = nadj[1] = 0;
        for (int i = 0; i < m; i++) {
            u = getint(); v = getint(); w = getint();
            if (w == 1235) { 
                if (find_set(u) != find_set(v)) {
                    k++; union_set(u, v);
                }
            }
            else if (w == 8977) { adj[0][nadj[0]][0] = u; adj[0][nadj[0]++][1] = v; }
            else { adj[1][nadj[1]][0] = u; adj[1][nadj[1]++][1] = v; }
        }
        
        s = 1235*k;
        for (int i = 0; (i < nadj[0]) && (k < n-1); i++)
            if (find_set(adj[0][i][0]) != find_set(adj[0][i][1])) {
                k++; s += 8977;
                union_set(adj[0][i][0], adj[0][i][1]);
            }
        for (int i = 0; (i < nadj[1]) && (k < n-1); i++)
            if (find_set(adj[1][i][0]) != find_set(adj[1][i][1])) {
                k++; s += 10923;
                union_set(adj[1][i][0], adj[1][i][1]);
            }
            
        printf("Instancia %d\n", c++);
        printf("%d\n\n", s);
    }

    return 0;
}
