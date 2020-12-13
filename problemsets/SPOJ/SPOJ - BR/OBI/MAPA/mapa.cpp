/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <math.h>
#include <set>

#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define DE 10000
#define MAXC 20001

using namespace std;

struct mapa {
    int x1, x2, y1, y2;
    double xc, yc, area;
};

mapa gugo[30001];

struct cmp {
    bool operator()(int a, int b) const {
        if (gugo[a].y1 < gugo[b].y1) return true;
        else if (gugo[a].y1 > gugo[b].y1) return false;
        if (a < b) return true; else return false;
    }
};

set<int> limx;
set<int, cmp> lista[500];
int indice[MAXC];
int m;


int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    s = (ch == '-') ? 1, ch = getchar() : 0;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    if (s) return -i;
    return i;
}


int main() {
    
    register int r, id, x1, y1, x2, y2, i, j, k = 1;
    double d1, d2;
    while (1) {
        m = get_int(); r = get_int(); if (!m && !r) break;
        limx.clear();
        for (i = 0; i < m; i++) {
            id = get_int(); x1 = get_int()+DE; y1 = get_int()+DE; x2 = get_int()+DE; y2 = get_int()+DE;
            gugo[id].x1 = x1; gugo[id].y1 = y1; gugo[id].x2 = x2; gugo[id].y2 = y2;
            gugo[id].area = (double)(x2-x1)*(double)(y2-y1); gugo[id].xc = x1+((x2-x1)/2.); gugo[id].yc = y1+((y2-y1)/2.);
            limx.insert(x2);
        }
        lista[0].clear(); set<int>::iterator it1 = limx.begin();
        for (i = 0, j = 0; i < MAXC; i++) { 
            indice[i] = j; if (it1 != limx.end() && i==*it1) lista[++j].clear(), it1++;
        }
        for (i = 1; i <= m; i++)
            for (j = indice[gugo[i].x1]; j <= indice[gugo[i].x2]; j++)
                lista[j].insert(i);
        printf("Teste %d\n", k++);
        for (i = 0; i < r; i++) {
            x1 = get_int()+DE; y1 = get_int()+DE; j = 0;
            foreach(it, all(lista[indice[x1]])) {
                id = *it; if (gugo[id].y1 > y1) break;
                if (x1 >= gugo[id].x1 && x1 <= gugo[id].x2 && y1 >= gugo[id].y1 && y1 <= gugo[id].y2) {
                if (!j) j = id;
                else if (gugo[id].area < gugo[j].area) j = id;
                else if (gugo[id].area == gugo[j].area) {
                    d1 = (gugo[id].xc-x1)*(gugo[id].xc-x1); d1 += (gugo[id].yc-y1)*(gugo[id].yc-y1);
                    d2 = (gugo[j].xc-x1)*(gugo[j].xc-x1); d2 += (gugo[j].yc-y1)*(gugo[j].yc-y1);
                    if (d1 < d2) j = id;
                    else if (d1==d2 && id < j) j = id;
                }
                }
            }
            printf("%d\n", j);
        }
        putchar('\n');
    }
    return 0;
}

