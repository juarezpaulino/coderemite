/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>

#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define min(a, b) ((a)<(b)?(a):(b))

const int VT = 100;
const int NCT = 500;
const int AR = 1000;
const int INF = 0x3F3F3F3F;
const int NULO = -1;


int dest[AR], label[AR];
int adj[VT][NCT];
int nadj[VT], nvt, nar, prof[VT];
char ponte[NCT];
int menor[VT], nponte;
_inline(int inv)(int a) { return a ^ 0x1; }


_inline(void inic)(int n = 0) {
    nvt = n; nar = 0;
    for (int i = 0; i < n; i++) nadj[i] = prof[i] = 0;
}

_inline(void aresta)(int i, int j, int c) {
    dest[nar] = j; label[nar] = c; adj[i][nadj[i]++] = nar++;
    dest[nar] = i; label[nar] = c; adj[j][nadj[j]++] = nar++;
}

void dfs_partponte(int no, int ent) {
    int i, ar, viz;
    for (i = 0; i < nadj[no]; i++) {
        ar = adj[no][i]; viz = dest[ar];
        if (prof[viz] == NULO) {
            menor[viz] = prof[viz] = prof[no] + 1;
            dfs_partponte (viz, ar);
            if (menor[viz] >= prof[no]) {
                if (menor[viz] == prof[viz]) ponte[label[ar]] = 1;
            } else menor[no] = min(menor[no], menor[viz]);
        } else if (inv(ar) != ent) menor[no] = min(menor[no], prof[viz]);
    }
}

void partponte() {
    for (int i = 0; i < nvt; i++) prof[i] = menor[i] = NULO;
    for (int i = 0; i < nvt; i++)
        if (prof[i] == NULO) {
            menor[i] = prof[i] = 0;
            dfs_partponte(i, NULO);
        }
}

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() )
        i = 10 * i + (ch - '0');
    return i;
}

void dfs(int v) {
    register int i, x; prof[v] = 1;
    for (i = 0; i < nadj[v]; i++) { x = dest[adj[v][i]]; if (!prof[x]) dfs(x); }
}


int n, c, nc;
int conf[VT][NCT], nconf[VT];
int conex[NCT][2], nconex[NCT];
int mini, odd[2], nodd;


int main() {

    register int i, j, k, x;

    while (1) {
        n = get_int(); c = get_int(); if (!n && !c) break;

        for (i = 0; i < n; i++) ponte[i] = nconex[i] = 0;
        for (i = nc = 0; i < c; i++) { k = get_int(); if (k) {
            for (j = 0; j < k; j++) {
                x = get_int(); conf[nc][j] = x; conex[x][nconex[x]++] = nc;
            }
            nconf[nc++] = k;
        } }

        inic(nc);
        for (i = 0; i < n; i++) if (nconex[i]==2) aresta(conex[i][0],conex[i][1],i);

        dfs(nvt-1);
        for (i = 0; i < nvt; i++) if (!prof[i]) break;
        if (i < nvt) { puts("-1"); continue; }

        for (i = nodd = 0; i<nvt && nodd<=2; i++) if (nadj[i]&1) odd[nodd++] = i;
        if (!nodd) { puts("0"); continue; }
        if (nodd > 2) { puts("-1"); continue; }

        partponte();
        mini = INF;
        for (i = 0; i < nodd; i++) { x = odd[i];
            if (nconf[x]==1) { if (mini > conf[x][0]) mini = conf[x][0]; continue; }
            for (j = 0; j < nconf[x]; j++) { k = conf[x][j];
                if (!ponte[k] || nconex[k]==1) { if (mini > k) mini = k; }
            }
        }
        printf("%d\n", mini);
    }
}

