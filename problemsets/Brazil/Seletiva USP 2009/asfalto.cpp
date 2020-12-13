/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
/* Seletiva USP 2009 - Problema D - asfalto.cpp
 * 
 * Tecnica: Arvore / Decomposicao por orelhas
 *
 * Entrada: Uma arvore com pesos nas arestas.
 * Saida: Contabilizar a soma de todos os caminhos possiveis entre cada par de 
 * no.
 *
 * Tecnica: Quantos caminhos passam por uma determinada aresta 'i' na arvore?
 * f[i] = Produto da quantidade de vertices em um lado da arvore pelo outro
 * lado.
 * Soma total = soma{f[i]*c[i]} para toda aresta i.
 * Caso base: Quando um no j e folha, contabilizamos:
 * (n - numero de nos representados) * (numero de nos representados) * c[i],
 * sendo i a unica aresta ligando a folha.
 *
 * Cuidados: Manter um vetor dinamico de adjacencias em vez de uma matriz
 * adj[10000][10000], pois ha estouro de memoria. Com o vetor dinamico, cada
 * no ocupa o que necessita de arestas. Lembrando que existem n-1 arestas 
 * apenas
 *
 */ 


#include <stdio.h>
#include <queue>
#include <vector>

#define _foreach(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

using namespace std;

struct aresta { int v, p; aresta(int v, int p) : v(v), p(p) {} };

int t, n;
vector<aresta> adj[10000];
// eat - numero de vertices aglutinados.
int nadj[10000], eat[10000];
queue<int> q;

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) i = (i<<3)+(i<<1)+(ch-'0');
    return i;
}


int main() {
    int a, b, c;
    int i, s;
    for (t = get_int(); t--; ) {
        n = get_int();
        for (i = 0; i < n; i++) adj[i].clear(), nadj[i] = eat[i] = 0;
        for (i = 0; i < n-1; i++) {
            a = get_int()-1, b = get_int()-1, c = get_int();
            adj[a].push_back(aresta(b, c)); adj[b].push_back(aresta(a, c));
            nadj[a]++; nadj[b]++;
        }
        
        for (i = 0; i < n; i++) { eat[i] = 1; if (nadj[i]==1) q.push(i); }
        for (s = 0; !q.empty(); ) {
            a = q.front(); q.pop(); nadj[a]--;
            foreach(it, all(adj[a])) if (nadj[it->v]) {
                b = it->v; c = it->p; s = (s+(n-eat[a])*(eat[a])*c)%1300031;
                nadj[b]--; eat[b]+=eat[a]; if (nadj[b]==1) q.push(b);
            }
        }
        printf("%d\n", s);
    }    
    
    return 0;
}
