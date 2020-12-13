/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <string.h>

using namespace std;

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-13;

const int VT = 1003;
const int AR = VT * VT;
    
////////////////////////////////////////////////////////////////////////////
// Definições compartilhadas.
//
int dest[AR];
int adj[VT][VT];
int nadj[VT], nvt, nar;
int prof[VT], ord[VT], nord;
int tes[VT];


////////////////////////////////////////////////////////////////////////////
// Inicializa o grafo.
//
void inic(int n = 0) {
    nvt = n; nar = 0;
    for (int i = 0; i < n; i++) nadj[i] = 0;
}

////////////////////////////////////////////////////////////////////////////
// Adiciona uma aresta ao grafo.
//
int aresta(int i, int j) {
    int ar = nar;
    dest[nar] = j;
    adj[i][nadj[i]++] = nar++;
    return ar;
}

////////////////////////////////////////////////////////////////////////////////
// Ordenação Topológica (duas primeiras funções).
//
void dfs_topsort(int no) {
    for (int i = 0; i < nadj[no]; i++) {
        int ar = adj[no][i], viz = dest[ar];
        if (prof[viz] == NULO) {
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

int max_path(int s, int t) {
    
    int dist[VT], i, j, k, m;
    for (k = s; k < nvt; k++) dist[k] = -INF;
    dist[t] = 0;
    for (k = t-1; k >= s; k--) {
        i = ord[k];
        for (m = 0; m < nadj[i]; m++) {
            j = dest[adj[i][m]];
            if (dist[i] < tes[i]+dist[j]) dist[i] = tes[i]+dist[j];
        }
    }
    return dist[s];
}


int main() {

    int n, q, p, x;
    int i;

    while (scanf("%d", &n)) {
        if (!n) break;
        inic(n+2); tes[0] = tes[n+1] = 0;
        for (i = 1; i <= n; i++) {
            scanf("%d %d", &q, &p); tes[i] = q;
            while (p--) { scanf("%d", &x); aresta(i, x); }
            aresta(0, i); aresta(i, n+1);
        }
        topsort();
        printf("%d\n", max_path(0, n+1));
    }

    return 0;
}
