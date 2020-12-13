/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int VT = 1010;
const int AR = VT * VT;

int dest[AR*2];
int adj[VT][VT], viz[VT][VT];
int nadj[VT], nvt, nar;
inline int inv(int a) { return a ^ 0x1; }

int prof[VT];

char part[VT], ponte[AR*2];
int menor[VT], npart, nponte;

void inic(int n = 0) {
    nvt = n; nar = 0;
    for (int i = 0; i < nvt; i++) {
        nadj[i] = 0;
        for (int j = 0; j < nvt; j++) viz[i][j] = 0;
    }
}

int aresta(int i, int j) {
    int ar = nar;
    dest[nar] = j; adj[i][nadj[i]++] = nar++;
    dest[nar] = i; adj[j][nadj[j]++] = nar++;
    return ar;
}

int dfs_partponte(int no, int ent) {
    int nf = 0;
    for (int i = 0; i < nadj[no]; i++) {
        int ar = adj[no][i], viz = dest[ar];
        if (prof[viz] == -1) {
            menor[viz] = prof[viz] = prof[no]+1;
            dfs_partponte(viz, ar); nf++;
            if (menor[viz] >= prof[no]) {
                part[no] = 1;
                if (menor[viz] == prof[viz]) ponte[ar] = ponte[inv(ar)] = 1;
            }
            else menor[no] = min(menor[no], menor[viz]);
        }
        else if (inv(ar) != ent) menor[no] = min(menor[no], prof[viz]);
    }
    return nf;
}

void partponte() {
    for (int i = 0; i < nvt; i++) part[i] = 0;
    for (int i = 0; i < nar; i++) ponte[i] = 0;
    for (int i = 0; i < nvt; i++) prof[i] = -1;
    for (int i = 0; i < nvt; i++) menor[i] = -1;
    npart = nponte = 0;
    for (int i = 0; i < nvt; i++) if (prof[i] == -1) {
        menor[i] = prof[i] = 0;
        if (dfs_partponte(i, -1) < 2) part[i] = 0;
    }
    for (int i = 0; i < nvt; i++) if (part[i]) npart++;
    for (int i = 0; i < nar; i++) if (ponte[i]) nponte++;
    nponte /= 2;
}

int main() {

    int N;
    while (scanf("%d", &N) != EOF) {
        inic(N);
        for (int i = 0; i < N; i++) {
            int u, k, v;
            scanf("%d (%d)", &u, &k);
            while (k--) {
                scanf("%d", &v);
                if (!viz[u][v]) viz[u][v] = viz[v][u] = 1, aresta(u, v);
            }
        }
        partponte();
        vector<pair<int,int> > P;
        for (int i = 0; i < nar; i++) if (ponte[i]) {
            int u = dest[i], v = dest[inv(i)];
            if (v < u) swap(u,v);
            P.push_back(make_pair(u,v));
            i++;
        }
        sort(P.begin(), P.end());
        printf("%d critical links\n", nponte);
        for (int i = 0; i < P.size(); i++) printf("%d - %d\n", P[i].first, P[i].second);
        putchar('\n');
    }

    return 0;
}
