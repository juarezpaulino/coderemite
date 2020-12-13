/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

const int VT = 110;
const int AR = VT * VT;

int dest[AR*2];
int adj[VT][VT*2];
int nadj[VT], nvt, nar;
inline int inv(int a) { return a ^ 0x1; }

int prof[VT];

char part[VT], ponte[AR*2];
int menor[VT], npart, nponte;

void inic(int n = 0) {
    nvt = n; nar = 0;
    memset(nadj, 0, sizeof(nadj));
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
    memset(part, 0, sizeof(part)),
    memset(ponte, 0, sizeof(ponte)),
    memset(prof, -1, sizeof(prof)),
    memset(menor, -1, sizeof(menor));
    npart = nponte = 0;
    for (int i = 0; i < nvt; i++) if (prof[i] == -1) {
        menor[i] = prof[i] = 0;
        if (dfs_partponte(i, -1) < 2) part[i] = 0;
    }
    for (int i = 0; i < nvt; i++) if (part[i]) npart++;
    for (int i = 0; i < nar; i++) if (ponte[i]) nponte++;
    nponte /= 2;
}

int N;
char S[100];

int main() {

    while (scanf("%d", &N)) {
        if (!N) break;
        inic(N);
        int u;
        while (scanf("%d", &u)) {
            if (!u) break;
            u--;
            gets(S);
            istringstream is(S);
            int v;
            while (is >> v) aresta(u,v-1);
        }
        partponte();
        printf("%d\n", npart);
    }

    return 0;
}
