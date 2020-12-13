/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <queue>


using namespace std;

#define MAX_ESTADO 5011

struct estado {
    int xb[20], yb[20], prof;
    char mapa[6][6];
    estado *prox;
};

int nb;
estado *hash[MAX_ESTADO];
char hor[20], tam[20];
estado s;

////////////////////////////////////////////////////////////////////////////////
// Inicializa a tabela hash.
//
void inic_hash() {
    for (int i = 0; i < MAX_ESTADO; i++) hash[i] = NULL;
}

///////////////////////////////////////////////////////////////////////////////
// Compara dois estados da tabela hash. retorna true se sao iguais. Dependente.
//
bool cmp_hash(estado *a, estado *b) {
    for (int i = 0; i < nb; i++)
        if (a->xb[i]!=b->xb[i] || a->yb[i]!=b->yb[i]) return false;
    return true;
}

////////////////////////////////////////////////////////////////////////////////
// Funcao hash - criatividade. Dependente.
//
int func_hash(estado *v) {
    int i, j;
    long long p;
    for (i = p = 0; i < 6; i++) {
        p <<= 6;
        for (j = 0; j < 6; j++) if (v->mapa[i][j]) p |= (1<<j);
    }
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
    int p = func_hash(v); estado *pt = hash[p], *ant = NULL;
    if (hash[p] == NULL) { hash[p] = cria_hash(v); return NULL; }
    while (pt != NULL) { 
        if (cmp_hash(v, pt)) return pt;
        ant = pt;  pt = pt->prox;
    }
    ant->prox = cria_hash(v); return NULL;
}


int BFS() {
    estado u, t, v, *pt;
    queue<estado> q;
    int i, j, k;
    
    inic_hash(); insere_hash(&s); q.push(s);
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (i = 0; i < nb; i++) {
            t = u; t.prof++;
            if (hor[i]) {
                for (j = 0; j < tam[i]; j++) t.mapa[t.yb[i]][t.xb[i]+j] = 0;
                for (j = -1; u.xb[i]+j>=0 && !u.mapa[u.yb[i]][u.xb[i]+j]; j--) {
                    v = t; v.xb[i] += j;
                    for (k = 0; k < tam[i]; k++) v.mapa[v.yb[i]][v.xb[i]+k] = 1;
                    if ((pt = insere_hash(&v)) == NULL) q.push(v);
                }
                for (j = 1; u.xb[i]+j+tam[i]-1<6 && !u.mapa[u.yb[i]][u.xb[i]+j+tam[i]-1]; j++) {
                    v = t; v.xb[i] += j;
                    for (k = 0; k < tam[i]; k++) v.mapa[v.yb[i]][v.xb[i]+k] = 1;
                    if ((pt = insere_hash(&v)) == NULL) q.push(v);
                }
                if (!i && u.xb[i]+j+tam[i]-1>=6) return t.prof;
            }
            else {
                for (j = 0; j < tam[i]; j++) t.mapa[t.yb[i]+j][t.xb[i]] = 0;
                for (j = -1; u.yb[i]+j>=0 && !u.mapa[u.yb[i]+j][u.xb[i]]; j--) {
                    v = t; v.yb[i] += j;
                    for (k = 0; k < tam[i]; k++) v.mapa[v.yb[i]+k][v.xb[i]] = 1;
                    if ((pt = insere_hash(&v)) == NULL) q.push(v);
                }
                for (j = 1; u.yb[i]+j+tam[i]-1<6 && !u.mapa[u.yb[i]+j+tam[i]-1][u.xb[i]]; j++) {
                    v = t; v.yb[i] += j;
                    for (k = 0; k < tam[i]; k++) v.mapa[v.yb[i]+k][v.xb[i]] = 1;
                    if ((pt = insere_hash(&v)) == NULL) q.push(v);
                }
            }
        }
    }
    
    return -1; 
}


int main() {
    int c;
    int i, j, k, m;
    int x, y;
    
    scanf("%d", &m);
    for (c = 1; c <= m; c++) {
        scanf("%d %d", &s.yb[0], &s.xb[0]); hor[0] = 1; tam[0] = 2; nb = 1;
        scanf("%d", &k); for (i = 0; i < k; i++) {
            scanf("%d %d", &s.yb[nb], &s.xb[nb]); hor[nb] = 0; tam[nb++] = 2;
        }
        scanf("%d", &k); for (i = 0; i < k; i++) {
            scanf("%d %d", &s.yb[nb], &s.xb[nb]); hor[nb] = 0; tam[nb++] = 3;
        }
        scanf("%d", &k); for (i = 0; i < k; i++) {
            scanf("%d %d", &s.yb[nb], &s.xb[nb]); hor[nb] = 1; tam[nb++] = 2;
        }
        scanf("%d", &k); for (i = 0; i < k; i++) {
            scanf("%d %d", &s.yb[nb], &s.xb[nb]); hor[nb] = 1; tam[nb++] = 3;
        }
        s.prof = 0;
        for (i = 0; i < 6; i++) for (j = 0; j < 6; j++) s.mapa[i][j] = 0;
        for (i = 0; i < nb; i++) {
            x = s.xb[i]; y = s.yb[i];
            if (!hor[i]) for (j = 0; j < tam[i]; j++) s.mapa[y+j][x] = 1;
            else for (j = 0; j < tam[i]; j++) s.mapa[y][x+j] = 1;
        }
        
        printf("The minimal number of moves to solve puzzle %d is %d.\n", c, BFS());
    }
    return 0;
}
