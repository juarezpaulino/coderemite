/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/***********************************************************************************************************/
/*                                 Declarations, macros, parser functions                                  */
/***********************************************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

#define FOR(i,m,n) for((i)=(m);(i)<(n);(i)++)
#define FORE(i,m,n) for((i)=(m);(i)<=(n);(i)++)
#define ROF(i,m,n) for((i)=(m);(i)>=(n);(i)--)
#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SI(a) ((a).size())
#define PB push_back
#define MP make_pair
#define CLR(a,v) memset((a),(v),sizeof(a))
#define SORT(v) sort(ALL(v))
#define UNIQUE(v) SORT(v),(v).resize(unique(ALL(v))-(v).begin())
#define LET(k,val) typeof(val) k = (val)


inline string ITOA(int a) {
    char c[500]; sprintf(c, "%d", (a)); return string(c);
}

typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<VI> VVI;
typedef vector<VD> VVD;
typedef vector<VS> VVS;
typedef pair<int,int> PII;
typedef signed long long i64;
typedef unsigned long long u64;

#define EPS 1E-9
#define INF 0x3F3F3F3F
#define DINF 1E16
#define NULO -1
#define PI 3.1415926535897932384626433832795

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


int get_int() {
    int ch, i, s;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    if (ch=='<' || ch=='=') return ch;
    s = (ch=='-') ? (ch=getchar(),-1) : 1;
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return s*i;
}

int pt[50], G[50][50];
int n, m, g;

const int VT = 900;
const int AR = VT*6;

int dest[AR];
int adj[VT][VT*2];
int nadj[VT], nvt, nar;
inline int inv(int a) { return a ^ 0x1; }

int cap[AR], fluxo[AR], ent[VT];
inline int orig(int a) { return dest[inv(a)]; }
inline int capres(int a) { return cap[a] - fluxo[a]; }

int padj[VT], lim[VT], nivel[VT], qtd[VT];

void inic(int n = 0) {
    nvt = n; nar = 0;
    CLR(nadj, 0);
}

int aresta(int i, int j, int u = 0, double c = 0) {
    int ar = nar;
    cap[nar] = u;
    dest[nar] = j; adj[i][nadj[i]++] = nar++;
    cap[nar] = 0;
    dest[nar] = i; adj[j][nadj[j]++] = nar++;
    return ar;
}

/*******************************************************************************
 * Fluxo Maximo - O(n^2 * m)
 * Dep: inic(), aresta(), inv(), orig(), capres()
 * Decl: dest[AR*2], adj[VT][VT*2], nadj[VT], nvt, nar, padj[VT], lim[VT],
 * nivel[VT], qtd[VT].
 */
void revbfs(int ini, int fim) {
    int i, no, viz, ar;
    queue<int> fila;
    CLR(nivel, NULO); CLR(qtd, 0);
    nivel[fim] = 0; fila.push(fim);
    while (!fila.empty()) {
        no = fila.front(); fila.pop(); qtd[nivel[no]]++;
        FOR(i,0,nadj[no]) {
            ar = adj[no][i]; viz = dest[ar];
            if (cap[ar] == 0 && nivel[viz] == NULO)
                nivel[viz] = nivel[no]+1, fila.push(viz);
        }
    }
}
int admissivel(int no) {
    while (padj[no] < nadj[no]) {
        int ar = adj[no][padj[no]];
        if (nivel[no]==nivel[dest[ar]]+1 && capres(ar)>0) return ar;
        padj[no]++;
    }
    padj[no] = 0; return NULO;
}
int retrocede(int no) {
    int i, ar, viz, menor = NULO;
    if (--qtd[nivel[no]] == 0) return NULO;
    FOR(i,0,nadj[no]) {
        ar = adj[no][i]; viz = dest[ar]; if (capres(ar)<=0) continue;
        if (menor==NULO || nivel[viz]<nivel[menor]) menor = viz;
    }
    if (menor!=NULO) nivel[no] = nivel[menor];
    qtd[++nivel[no]]++;
    return ((ent[no] == NULO) ? no : orig(ent[no]));
}
int avanca(int no, int ar) {
    int viz = dest[ar];
    ent[viz] = ar; lim[viz] = min(lim[no], capres(ar));
    return viz;
}
int aumenta(int ini, int fim) {
    int ar, no = fim, fmax = lim[fim];
    while (no != ini) {
        fluxo[ar = ent[no]] += fmax; fluxo[inv(ar)] -= fmax; no = orig(ar);
    }
    return fmax;
}
int maxflow(int ini, int fim) {
    int ar, no = ini, fmax = 0;
    CLR(fluxo, 0); CLR(padj, 0);
    revbfs(ini, fim); lim[ini] = INF; ent[ini] = NULO;
    while (nivel[ini]<nvt && no!=NULO)
        if ((ar = admissivel(no)) == NULO) no = retrocede(no);
        else if ((no = avanca(no, ar)) == fim) {
            fmax += aumenta(ini, fim); no = ini;
        }
    return fmax;
}


int main() {

    int x, ch, y, i, j, k, r, id = 0;

    for (; n=get_int(),m=get_int(),g=get_int(), n+m+g;) {
        id++;
        CLR(pt,0); CLR(G,0); k = g;
        while (k--) {
            x = get_int(); ch = get_int(); y = get_int();
            if (ch=='<') pt[y]+=2; else pt[y]++, pt[x]++;
            G[x][y]++; G[y][x]++;
        }

        // Dream team must win all other matches.
        FOR(i,1,n) FOR(j,G[0][i],m) pt[0]+=2, g++;

        FOR(i,1,n) if (pt[0] <= pt[i]) break;
        if (i < n) { printf("N\n"); continue; }

        // The number of points of dream team determines the capacities
        // from edges linked to source. FM = m*n*(n-1) - 2*g
        pt[0]--;
        inic(n*(n-1)/2+n+2);
        FOR(i,1,n) aresta(0,i,pt[0]-pt[i]);
        k = n; r = 0;
        FOR(i,1,n) FOR(j,i+1,n) if (G[i][j] < m) {
            aresta(i,k,(m-G[i][j])*2);
            aresta(j,k,(m-G[i][j])*2);
            aresta(k,nvt-1,(m-G[i][j])*2);
            k++; r+=(m-G[i][j])*2;
        }
        if (maxflow(0,nvt-1) == r) printf("Y\n");
        else printf("N\n");
    }

    return 0;
}
