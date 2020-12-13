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


const int VT = 105;
const int AR = VT * VT;

int dest[AR];
int adj[VT][VT];
int nadj[VT], nvt, nar;
char color[VT];
char imp;

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

void dfs(int no, char cor) {
    color[no] = cor;
    for (int i = 0; (i < nadj[no]) && !imp; i++) {
        int ar = adj[no][i], viz = dest[ar];
        if (color[viz] == NULO) dfs(viz, cor^1);
        else if (color[no] == color[viz]) imp = 1;
    }
}


int main() {

    int n, m;
    int x, y;
    int c = 1;
 
    while (scanf("%d %d", &n, &m) != EOF) {
        inic(n);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            aresta(x, y);
        }
        memset(color, NULO, sizeof(color));
        imp = 0;
        for (int i = 0; (i < n) && (!imp); i++)
            if (color[i] == NULO) dfs(i, 0);
        
        printf("Instancia %d\n", c++);
        if (!imp) puts("sim\n");
        else puts("nao\n");
    }    
    
    return 0;
}
