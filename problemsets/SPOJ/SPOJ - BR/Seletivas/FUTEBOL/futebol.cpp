/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <string.h>
#include <ctype.h>

using namespace std;

struct futebol {
    char nome[20], s[20];
    int pt, nj, gm, gs, sg;
    double ap;
};

int t, g;
futebol times[30];
map<string, int> m;
char st;


int cmp(const void *a, const void *b) {
    futebol *x = (futebol *)a, *y = (futebol *)b;
    if (x->pt > y->pt) return -1;
    else if (x->pt < y->pt) return 1;
    else if (x->sg > y->sg) return -1;
    else if (x->sg < y->sg) return 1;
    else if (x->gm > y->gm) return -1;
    else if (x->gm < y->gm) return 1;
    if (st) return (strcmp(x->nome, y->nome));
    return 0;
}


int main() {
    
    int i, j;
    char a[40], b[40], ch;
    int u, v;
    int x, y;
    char nwl = 0;
    
    while (scanf("%d %d ", &t, &g) != EOF) {
        if (!t && !g) break;
        if (nwl) putchar('\n');
        m.clear();
        for (i = 0; i < t; i++) {
            gets(times[i].s);
            m[times[i].s] = i;
            for (j = 0; ch = times[i].s[j]; j++) 
                if (ch>='A'&&ch<='Z') times[i].nome[j] = ch-'A'+'a';
                else times[i].nome[j] = ch;
            times[i].pt = times[i].nj = times[i].gm = times[i].gs = 0;
        }
        for (i = 0; i < g; i++) {
            scanf(" %s %d - %d %s ", a, &x, &y, b);
            u = m[a]; v = m[b];
            times[u].nj++; times[v].nj++;
            times[u].gm += x; times[v].gm += y; times[u].gs += y; times[v].gs += x;
            if (x > y) times[u].pt += 3;
            else if (x < y) times[v].pt += 3;
            else { times[u].pt++; times[v].pt++; }
        }
        for (i = 0; i < t; i++) {
            times[i].sg = times[i].gm-times[i].gs;
            if (times[i].nj) times[i].ap = (times[i].pt)*100.0 / (times[i].nj*3.0);
        }
        st = 1;
        qsort(times, t, sizeof(futebol), cmp);
        st = 0;
        if (times[0].nj) printf(" 1. %15s %3d %3d %3d %3d %3d %6.2lf\n", times[0].s, \
                      times[0].pt, times[0].nj, times[0].gm, times[0].gs, times[0].sg, times[0].ap);
        else printf(" 1. %15s %3d %3d %3d %3d %3d %6s\n", times[0].s, \
             times[0].pt, times[0].nj, times[0].gm, times[0].gs, times[0].sg, "N/A");
        for (i = 1; i < t; i++) {
            if (cmp(&times[i-1], &times[i])) printf("%2d. ", i+1);
            else printf("    ");
            if (times[i].nj) printf("%15s %3d %3d %3d %3d %3d %6.2lf\n", times[i].s, \
                          times[i].pt, times[i].nj, times[i].gm, times[i].gs, times[i].sg, times[i].ap);
            else printf("%15s %3d %3d %3d %3d %3d %6s\n", times[i].s, \
                 times[i].pt, times[i].nj, times[i].gm, times[i].gs, times[i].sg, "N/A");
        }
        nwl = 1;
    }
    
    return 0;
}
