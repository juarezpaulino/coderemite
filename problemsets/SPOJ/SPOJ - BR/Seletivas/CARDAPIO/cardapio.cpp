/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>
#include <sstream>
#include <map>
#include <queue>


using namespace std;

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")
#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-13;

_inline(int cmp)(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


const int VT = 2010;
const int AR = VT;

int dest[AR<<1];
int adj[VT][VT<<1];
int nadj[VT], nvt, nar;
int prof[VT];

int ord[VT], comp[VT], repcomp[VT], nord, ncomp;
_inline(int transp)(int a) { return (a & 0x1); }

_inline(int verd)(int v) { return v<<1 | 1; }
_inline(int falso)(int v) { return v<<1; }


void inic(int n = 0) {
    nvt = n;
    nar = 0;
    memset(nadj, 0, sizeof(nadj));
}

int aresta(int i, int j) {
    int ar = nar;
    dest[nar] = j;
    adj[i][nadj[i]++] = nar++;
    dest[nar] = i;
    adj[j][nadj[j]++] = nar++;
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

map<string, int> m;


int main() {
    
    int n;
    int i;
    char str1[30], str2[30];
    char *s1, *s2;
    int x1, x2;
    bool v1, v2;
    int nvar;
    int c = 1;
    
    while (scanf("%d ", &n) != EOF) {
        m.clear();
        inic();
        nvar = 0;
        for (i = 0; i < n; i++) {
            scanf("%s %s ", str1, str2);
            v1 = (*str1 == '!') ? 0 : 1; v2 = (*str2 == '!') ? 0 : 1;
            s1 = (v1) ? str1 : str1+1; s2 = (v2) ? str2 : str2+1;
            if (m.find(s1) != m.end()) x1 = m[s1];
            else x1 = m[s1] = nvar++;
            if (m.find(s2) != m.end()) x2 = m[s2];
            else x2 = m[s2] = nvar++;
            clausula(x1, v1, x2, v2);
        }
        nvt = nvar<<1;
        
        printf("Instancia %d\n", c++);
        if (twosat(nvar)) puts("sim\n");
        else puts("nao\n");
    }
    
    return 0;
}
