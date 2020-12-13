/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <string.h>
#include <list>
#include <map>
#include <set>
#include <string>

using namespace std;

#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define INF 0x3F3F3F3F

const int VT = 505;

typedef pair<int,int> ar;

int nvt = 0;
char est[VT][VT];
list<ar> adj[VT], ent[VT][VT];
map<string, int> m;
char ct[VT][40];
int maxv[VT];
int s, t;


void inic() {
    for (int i = 1; i < nvt; i++) adj[i].clear();
    nvt = 1;
}

void path(int k, int v, int u) {
    int x, y;
    
    if (v == t) { printf("%s\n", ct[v]); return; }
    printf("%s ", ct[v]);
    x = INF;
    foreach (it, all(ent[k][v]))
        if (it->second >= u && it->first < x) {
            x = it->first; y = it->second;
        }
    path(k-1, x, y);
}


int main() {

    int r;
    int i, j, k;
    int x, y, v;
    char z, c;
    char a[40], b[40];
    
    c = 0;
    while (scanf("%d ", &r) != EOF) {
        if (c) putchar('\n');
        m.clear(); inic();
        for (i = 0; i < r; i++) { 
            scanf("%s %s %d ", a, b, &v);
            if (!m.count(a)) { x = m[a] = nvt; strcpy(ct[nvt++], a); } else x = m[a];
            if (!m.count(b)) { y = m[b] = nvt; strcpy(ct[nvt++], b); } else y = m[b];
            adj[y].push_back(make_pair(x,v)); adj[x].push_back(make_pair(y,v));
        }
        scanf("%s %s ", a, b);
        if (!m.count(a)) { s = m[a] = nvt; strcpy(ct[nvt++], a); } else s = m[a];
        if (!m.count(b)) { t = m[b] = nvt; strcpy(ct[nvt++], b); } else t = m[b];
        
        if (s == t) { printf("%s\n", ct[s]); c = 1; continue; }
        
        for (i = 1; i < nvt; i++) { est[0][i] = 0; ent[0][i].clear(); maxv[i] = -1; }
        est[0][t] = 1; ent[0][t].push_back(make_pair(-1, INF)); maxv[t] = INF;

        z = 1;
        for (k = 1; !est[k-1][s] && z; k++) {
            z = 0;
            for (i = 1; i < nvt; i++) {
                est[k][i] = 0; ent[k][i].clear(); y = -1; x = INF;
                foreach(it, all(adj[i]))
                    if (est[k-1][it->first] && it->second > maxv[i]) {
                        foreach(it1, all(ent[k-1][it->first]))
                            if (it1->second >= it->second) {
                                est[k][i] = z = 1;
                                ent[k][i].push_back(make_pair(it->first, it->second));
                            }
                        if (est[k][i] && it->second > y) y = it->second;
                    }
                if (y > -1) maxv[i] = y;
            }
        }
        
        if (est[k-1][s]) path(k-1, s, 0);
        else printf("No valid route.\n");
        c = 1;
    }
    
    return 0;
}
