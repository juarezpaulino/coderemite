/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Seletiva USP 2009 - Problema I - bacterias.cpp
 *
 * Tecnica: Recorrencia em matrizes / Cadeia de markov
 *
 * Entrada: Numero de geracoes e a populacao para os 4 dias iniciais.
 * Saida: Numero de bacterias ao fim da  n-esima geracao.
 *
 * Tecnica: Suponha que voc� tem uma recorr�ncia linear para calcular a_n,
 * dependendo das vari�veis a_(n-1), ..., a_(n-k). Suporemos primeiro que tal
 * recorr�ncia linear n�o tem um "termo independente":
 *
 * a_n = (c_k)*a_(n-k) + ... (c_1)*a_(n-1)
 *
 * Ent�o, considerando o vetor (a_(n-k) ... a_(n-1))', onde o ' representa
 * transposi��o de matriz, � simples ver que a seguinte matriz:
 *
 * (0 1 0 0 ... 0 0)
 * (0 0 1 0 ... 0 0)
 * .
 * .
 * .
 * (0 0 0 0 ... 0 1)
 * (c_k c_(k-1) ... c_1)
 *
 * Leva o vetor (a_(n-k) ... a_(n-1))' em (a_(n-k+1) ... a_(n))' por meio de
 * uma multiplica��o � esquerda
 * (fa�a as multiplica��es para ver o que est� acontecendo!).
 *
 * Se tivermos um termo independente, podemos usar o seguinte truque. Suponha
 * que a recorr�ncia �:
 *
 * a_n = 2*a_(n-2) + a_(n-1) + 5
 *
 * Normalmente usar�amos um vetor-coluna com dois elementos, mas devido ao
 * termo independente, vamos fazer isso com 3: (a_(n-1) a_(n-2) 1)'. O 1 vai
 * ser mantido durante os produtos, para termos uma veri�vel para multiplicar
 * por uma constante qualquer e dar esta mesma constante. Ent�o, temos que a
 * matriz (resultante da matriz original ((0 1), (1,2)) pela adi��o de uma
 * coluna com o valor do termo independente e de uma linha da
 * forma (0 0 ... 1)):
 *
 * (0 1 0)
 * (2 1 5)
 * (0 0 1)
 *
 * � tal que o vetor (a_(n-2) a_(n-1) 1)' � levado em (a_(n-1) a_(n) 1)'.
 *
 * Em ambos os casos, uma vez calculada a matriz A em quest�o, podemos
 * calcular o n-�simo termo em tempo linear: Basta come�ar com o
 * vetor v = (a_1 ... a_k)' (ou (a_1 ... a_k 1)') e pegar o primeiro elemento
 * de A^(n-1) * v. Aproveitando-se do fato de que exponencia��o de matrizes d�
 * um algoritmo O(k^3 * log n) para calcular A, temos o algoritmo desejado.
 *
 */

#include <stdio.h>

#define MAXD 4
#define POWBIT 0x80000000

typedef long long ll;

struct mat { ll v[MAXD][MAXD]; int m, n; };

void copy_mat(mat &a, mat &r) {
    r.m = a.m, r.n = a.n;
    for (int i=0; i<a.m; i++) for (int j=0; j<a.n; j++) r.v[i][j]=a.v[i][j];
}

/*******************************************************************************
 * Multiplicacao matricial em O(mnk)
 */
void mult_mat(mat &a, mat &b, mat &r) {
    int i, j, k;
    r.m = a.m, r.n = b.n;
    for (i = 0; i < a.m; i++) for (j = 0; j < b.n; j++) r.v[i][j] = 0;
    for (i = 0; i < a.m; i++) for (j = 0; j < b.n; j++) for (k = 0; k < a.n; k++)
        r.v[i][j] = (r.v[i][j]+(a.v[i][k] * b.v[k][j])%13371337)%13371337;
}

/*******************************************************************************
 * Exponenciacao matricial em O(mnk * log p)
 * Dep: mult_mat, copy_mat
 */
void pow_mat(mat &a, int p, mat &r) {
    int i, j, k; mat c;
    for (k=31; !(p&POWBIT); k--, p<<=1); copy_mat(a, r);
    while (p<<=1, k--) {
        mult_mat(r, r, c); p&POWBIT ? mult_mat(c, a, r) : copy_mat(c, r);
    }
}

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}

mat t;
int n;

int main() {

    mat r, v, g;
    int i, j;
    ll s;

    /* Matriz de transicao */
    t.m = t.n = MAXD;
    t.v[0][1]=t.v[1][2]=t.v[2][3]=t.v[3][0]=t.v[3][1]=t.v[3][2]=t.v[3][3]=1;
    v.m = 4; v.n = 1;

    for (; n = get_int(), n;) {
        for (i = 0; i < MAXD; i++) v.v[i][0] = get_int();
        pow_mat(t, n-4, r); mult_mat(r, v, g);
        for (i = s = 0; i < 4; i++) s=(s+g.v[i][0])%13371337;
        printf("%d\n", (int)s);
    }

    return 0;
}
