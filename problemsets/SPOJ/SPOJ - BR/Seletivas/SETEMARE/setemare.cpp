/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <cstdlib>

using namespace std;

#define MAX_ESTADO 5011

struct estado {
    char mapa[9][9];
    int x, y, ex[9], ey[9];
    char ev[9];
    int prof, resta;
    estado *prox;
};

int ne;
estado *hashe[MAX_ESTADO];
estado s;

////////////////////////////////////////////////////////////////////////////////
// Inicializa a tabela hash.
//
void inic_hash() {
    for (int i = 0; i < MAX_ESTADO; i++) hashe[i] = NULL;
}

///////////////////////////////////////////////////////////////////////////////
// Compara dois estados da tabela hash. retorna true se sao iguais. Dependente.
//
bool cmp_hash(estado *a, estado *b) {
    if (a->x!=b->x || a->y!=b->y) return false;
    for (int i = 0; i < ne; i++)
        if (a->ex[i]!=b->ex[i] || a->ey[i]!=b->ey[i]) return false;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
// Funcao hash - criatividade. Dependente.
//
int func_hash(estado *v) {
    int i, j, p;
    p = (v->y*8+v->x)+17;
    for (i = p = 0; i < ne; i++) { p += (v->ey[i]*8+v->ex[i])+13; if (v->ev[i]) p+=7; }
    return p%MAX_ESTADO;
}

////////////////////////////////////////////////////////////////////////////////
// Insere elemento na tabela hash. Retorna o estado/NULL para falha/sucesso.
//
estado *cria_hash(estado *v) {
    estado *pt = (estado *) malloc(sizeof(estado));
    *pt = *v; pt->prox = NULL; return pt;
}

estado *insere_hash(estado *v) {
    int p = func_hash(v); estado *pt = hashe[p], *ant = NULL;
    if (hashe[p] == NULL) { hashe[p] = cria_hash(v); return NULL; }
    while (pt != NULL) {
        if (cmp_hash(v, pt)) return pt;
        ant = pt;  pt = pt->prox;
    }
    ant->prox = cria_hash(v); return NULL;
}


#define INF 0x3F3F3F3F

int dist(int x, int y, int ex, int ey) {
    int dx = abs(x-ex), dy = abs(y-ey);
    return (dx>dy)?dx:dy;
}

int sqr_dist(int x, int y, int ex, int ey) {
    return (x-ex)*(x-ex)+(y-ey)*(y-ey);
}


bool BFS() {
    estado u, v;
    int i, j, k, l, m, nx, ny, nex, ney, x, y;
    queue<estado> q;

    inic_hash(); insere_hash(&s); q.push(s);
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (i = -1; i < 2; i++) for (j = -1; j < 2; j++) {
            if (!i && !j) continue; nx = u.x+j; ny = u.y+i;
            if (ny<0 || ny>8 || nx<0 || nx>7 || u.mapa[ny][nx]!='.') continue;
            v = u; v.prof++;
            v.x = nx; v.y = ny; v.mapa[u.y][u.x] = '.'; v.mapa[ny][nx] = 'S';
            for (k = 0; k < ne; k++) {
                if (!v.ev[k]) continue;
                nex = ney = INF;
                for (l = -1; l < 2; l++) for (m = -1; m < 2; m++) {
                    if (!l && !m) continue; x = v.ex[k]+m; y = v.ey[k]+l;
                    if (y<0 || y>8 || x<0 || x>7) continue;
                    if (dist(nx, ny, x, y) < dist(nx, ny, nex, ney)) {
                        nex = x; ney = y;
                    }
                    else if (dist(nx, ny, x, y)==dist(nx, ny, nex, ney))
                        if (sqr_dist(nx, ny, x, y) < sqr_dist(nx, ny, nex, ney)) {
                            nex = x; ney = y;
                        }
                }
                if (nx==nex && ny==ney) break;
                if (v.mapa[ney][nex]<k) {
                    v.resta-=2; v.ev[v.mapa[ney][nex]] = v.ev[k] = 0;
                    v.mapa[ney][nex] = '#';
                }
                else if (v.mapa[ney][nex]=='#') { v.resta--; v.ev[k] = 0; }
                else v.mapa[ney][nex] = k;
                if (v.mapa[u.ey[k]][u.ex[k]]==k) v.mapa[u.ey[k]][u.ex[k]] = '.';
                v.ex[k] = nex; v.ey[k] = ney;
            }
            if (k < ne) continue; if (v.resta<=0) return true;
            if (v.prof == 9) continue;
            if (insere_hash(&v)==NULL) q.push(v);
        }
    }
    return false;
}


int main() {

    int n, i, j;

    scanf("%d ", &n);
    while (n--) {
        for (i = 0; i < 9; i++)
            gets(s.mapa[i]);
        getchar();
        s.prof = s.resta = ne = 0;
        for (i = 0; i < 9; i++)
            for (j = 0; j < 8; j++)
                if (s.mapa[i][j] == 'E') {
                    s.resta++; s.ex[ne] = j; s.ey[ne] = i; s.ev[ne] = 1;
                    s.mapa[i][j] = ne++;
                }
                else if (s.mapa[i][j] == 'S') { s.x = j; s.y = i; }
        if (BFS()) puts("I'm the king of the Seven Seas!");
        else puts("Oh no! I'm a dead man!");
    }

    return 0;
}
