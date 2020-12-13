/* Report Recovery */

#include <stdio.h>
#include <math.h>

#define min(a, b) ((a)<(b)?(a):(b))
#define max(a, b) ((a)>(b)?(a):(b))


char vd[5][11];          /* Nomes dos vendedores. */
int s;     /* Quantidade de vendedores. */
int n;     /* Quantidade de produtos. */

int m[5][26];           /* Matriz dos numeros. */
int len[5];             /* Tamanho de cada linha na matriz m. */

int indice[6];          /* Indice para solucao parcial de vendedores. */
int totals;

int bv[5][40][6];        /* Vetor de solucoes parciais do backtracking dos vendedores. */
int nbv[5];              /* Numero de solucoes encontradas para cada vendedor. */

int finished;           /* flag de backtrack. */
int sol[5];              /* Indice da solucao final. */
int tp[6];


void newl() {
    char ch;
    while ((ch = getchar()) != '\n');
}

int getvd(int v) {
    
    char ch;
    int i = 0;
    
    while ((ch = getchar()) >= 'A') vd[v][i++] = ch;
    vd[v][i] = '\0';
    
    i = 0;
    while ((ch >= '0') && (ch <= '9')) {
        m[v][i++] = ch - '0';
        ch = getchar();
    }
    len[v] = i;

    if ((vd[v][0] == 'T') && (vd[v][1] == 'P')) return 0;
    return 1;
}

/* Pega do vendedor v o numero indexado de first a last. */
int getvalor(int v, int first, int last) {
    
    int i;
    int peso;
    int num;
    
    peso = 1;
    num = 0;
    for (i = last-1; i >= first; i--) {
        num += m[v][i]*peso;
        peso *= 10;
    }
    
    return (num); 
}

int valida_solucao(int v,  int k, int sum) {

    return ((sum == totals)?1:0);
}

int valida_vd(int v, int k, int sum, int *ni) {
    
    if ((m[v][indice[k-2]] == 0) && (indice[k-1]-indice[k-2] != 1)) return (0);
    
    *ni = getvalor(v, indice[k-2], indice[k-1]);
    
    if ((sum+(*ni)) > totals) return 0;
    
    return (1);
}

void guarda_solucao(int v) {

    int i;
    
    bv[v][nbv[v]][n-1] = totals;
    for (i = 0; i < n-1; i++)
        bv[v][nbv[v]][i] = getvalor(v, indice[i], indice[i+1]);
    nbv[v]++;
}

void btk_vendedor(int v, int k,  int sum) {
    
    int i;
    int ni;
    int last;
    
    if (k == n) {
        if ((m[v][indice[n-2]] == 0) && (indice[n-1]-indice[n-2] != 1)) return;
        sum += getvalor(v, indice[n-2], indice[n-1]);
        if (valida_solucao(v, k, sum))
            guarda_solucao(v);
    }
    else if (k == 0) {
        last = len[v]-ceil((float)len[v]/n);
        /* Primeiro, escolhe a coluna de totals */
        for (i = max(n-1, len[v]-5); i <= last; i++)
            if ((m[v][i] != 0) || (i == last)) {
                indice[n-1] = i;
                totals = getvalor(v, i, len[v]);
                btk_vendedor(v, k+1, sum);
            }
    }
    else if (k == 1) {
        /* Primeiro indice sempre inicia em 0. */
        indice[k-1] = 0;
        btk_vendedor(v, k+1, sum);
    }
    else {
        for (i = indice[k-2]+1; i < min(indice[k-2]+5, indice[n-1]); i++) {
            indice[k-1] = i;
            if (valida_vd(v, k, sum, &ni))
                btk_vendedor(v, k+1, sum+ni);
        }
    }
}

int valida(int k, int sum[]) {
        
    int i;
    
    for (i = 0; i < n; i++)
        if (sum[i] != tp[i])
            return 0;
    return 1;
}

int valida_pn(int k, int sum[], int aux[]) {
    
    int i;
    
    for (i = 0; i < n; i++) {
        aux[i] = sum[i]+bv[k-1][sol[k-1]][i];
        if (aux[i] > tp[i])
            return 0;
    }
    return 1;
}

void backtrack(int k, int sum[]) {

    int i, j;
    int aux[6];

    if (k == s) {
        if (valida(k, sum))
            finished = 1;
    }
    else if (k == 0) {
        for (i = 0; i < nbv[s-1]; i++) {
            sol[s-1] = i;
            for (j = 0; j < n; j++)
                tp[j] = bv[s-1][i][j];
            backtrack(k+1, sum);    
        }
    }
    else {
        for (i = 0; i < nbv[k-1]; i++) {
            sol[k-1] = i;
            if (valida_pn(k, sum, aux)) {
                backtrack(k+1, aux);
                if (finished) return;
            }
        }
    }
}

void imprime() {
    
    int i, j;
    
    for (i = 1; i < n; i++) printf("P%d ", i);
    printf("Totals\n");
    for (i = 0; i < s; i++) {
        printf("%s", vd[i]);
        for (j = 0; j < n; j++)
            printf(" %d", bv[i][sol[i]][j]);
        putchar('\n');
    }
}


int main() {

    int cases;
    int i;
    char ch;
    int sum[6];
    
    scanf("%d", &cases);
    newl();
    while (cases--) {
        
        n = 1;
        while ((ch = getchar()) != 'T') {
            getchar();
            n++;
        }
        newl();
        
        s = 0;
        while (getvd(s)) s++;
        s++;
        
        /* Encontra as solucoes parciais para cada vendedor. */
        for (i = 0; i < s; i++) {
            nbv[i] = 0;
            btk_vendedor(i, 0, 0);
        }
        
        finished = 0;
        for (i = 0; i < n; i++)
            sum[i] = 0;
        backtrack(0, sum);
        imprime();
    }    
    
    return 0;
}

