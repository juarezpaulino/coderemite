/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <vector>

using namespace std;

#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()


const int VT = 20000;
const int AR = VT;

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-13;


short dest[AR<<1];
vector<short> adj[VT];
short nadj[VT], nvt, nar;
short prof[VT];

short ord[VT], comp[VT], repcomp[VT], nord, ncomp;
_inline(int transp)(int a) { return (a & 0x1); }

_inline(int verd)(int v) { return v<<1 | 1; }
_inline(int falso)(int v) { return v<<1; }


void inic(int n = 0) {
    for (int i = 0; i < nvt; i++) adj[i].clear();
    nvt = n;
    nar = 0;
    memset(nadj, 0, sizeof(nadj));
}

int aresta(int i, int j) {
    int ar = nar;
    dest[nar] = j;
    adj[i].push_back(nar++); nadj[i]++;
    dest[nar] = i;
    adj[j].push_back(nar++); nadj[j]++;
    return ar;
}

void dfs_topsort(int no) {
    for (int i = 0; i < nadj[no]; i++) {
        int ar = adj[no][i], viz = dest[ar];
        if (!transp(ar) && prof[viz] == NULO) {
            prof[viz] = prof[no] + 1; dfs_topsort(viz);
        }
    }
    ord[--nord] = no;
}

void topsort() {
    memset(prof, NULO, sizeof(prof));
    nord = nvt;
    for (int i = 0; i < nvt; i++)
        if (prof[i] == NULO) {
            prof[i] = 0; dfs_topsort(i);
        }
}

void dfs_compfortcon(int no) {
    comp[no] = ncomp;
    for (int i = 0; i < nadj[no]; i++) {
        int ar = adj[no][i], viz = dest[ar];
        if (transp(ar) && comp[viz] == NULO) dfs_compfortcon(viz);
    }
}

void clausula(int x, bool valx, int y, bool valy) {
    int hipA, teseA, hipB, teseB;
    if (valx) { hipA = falso(x); teseB = verd(x); }
    else { hipA = verd(x); teseB = falso(x); }
    if (valy) { hipB = falso(y); teseA = verd(y); }
    else { hipB = verd(y); teseA = falso(y); }
    aresta(hipA, teseA);
    aresta(hipB, teseB);
}

int compfortcon() {
    memset(comp, NULO, sizeof(comp));
    ncomp = 0;
    topsort();
    for (int i = 0; i < nvt; i++)
        if (comp[ord[i]] == NULO) {
            repcomp[ncomp] = ord[i];
            dfs_compfortcon(ord[i]);
            ncomp++;
        }
    return ncomp;
}

int twosat(int nvar) {
    compfortcon();
    for (int i = 0; i < nvar; i++)
        if (comp[verd(i)] == comp[falso(i)])
            return 0;
    return 1;
}


int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

int c, p;


int main() {
    
    int i, x, y, s, t;
    for (; c = get_int(), p = get_int(), c+p; ) {
        p++; inic(p<<1);
        for (i = 0; i < c; i++) {
            x = get_int(); y = get_int(); s = get_int(); t = get_int();
            if (!x && y) clausula(y, 1, y, 1);
            else if (x && !y) clausula(x, 1, x, 1);
            else if (x && y) clausula(x, 1, y, 1);
            if (!s && t) clausula(t, 0, t, 0);
            else if (s && !t) clausula(s, 0, s, 0);
            else if (s && t) clausula(s, 0, t, 0);
        }
        if (twosat(p)) puts("yes"); else puts("no");
    }
    
    return 0;
}
