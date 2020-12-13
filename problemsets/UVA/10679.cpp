/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <string>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// Aho-Corasick
//
// A. Detalhes do Algoritmo:
//
// 1) A arvore AC nada mais é que uma "trie" com links de falha e atributos de
// saida
//
// 2) Uma falha falha[i] é um link referente ao nodo i; e simboliza um link
// para o nodo na árvore AC que representa o maior prefixo que é um sufixo
// proprio do ramo de i.
//
// 3) Um atributo de saida
//
///////////////////////////////////////////////////////////////////////////////
//
// B. Variáveis Globais:
//
// - mapach trans[u]: Mapa de transicao da "trie" de um no u com uma letra
// especifica. Ex: v = trans[u]['a'].
//
// - mapastr patt: Mapa de identificacao de um padrao para um inteiro. Ex:
// int p = patt["mississipi"].
//
// - list<int> pos[k]: após fazer a busca em um texto, retorna a posicao de
// todas as ocorrencias do padrão referenciado por k = patt[str] no texto.
//
// - falha[u]: link referente ao nodo u; e simboliza um link para o nodo na
// árvore AC que representa o maior prefixo que é um sufixo proprio do ramo
// de u.
//
// - output[u]: Caso o nodo u seja um nodo output na arvore AC,
// output[u] = patt[str] retorna o identificador para a string encontrada no
// ramo ate u.
//
// - len[k] Tamanho da string referenciada por k = patt[str].
//
// - N: Numero final de nos na arvore AC.
//
///////////////////////////////////////////////////////////////////////////////
//
// C. Procedimentos de Uso:
//
// - init(): Inicializacao - Uma chamada por instancia do problema (antes de
// todas as outras funcoes);
//
// - insert_patt(char *s): Insere um padrao ao automato reconhecedor (arvore
// trie). Retorna o indice de acesso ao padrao cadastrado na variavel global
// pos.
//
// - compile(): Gera o tratamento de falhas e atualiza o atributo de saida
// dos nodos da arvore AC. Chamar "uma vez" apos insercao dos padroes.
//
// - search(char *s): Consulta o texto "s" em busca dos padroes cadastrados.
// Chamar apos compile(). Preenche a variavel global pos[].
//
////////////////////////////////////////////////////////////////////////////////

#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define ALL(v) (v).begin(), (v).end()

const int MAX_NO = 1000100;
const int MAX_PAD = 1010;
typedef map<char, int> mapach;
typedef map<string, int> mapastr;

// O Windows nao me deixou declarar na estrutura. =(
mapach trans[MAX_NO];
int DP[MAX_NO];
mapastr patt;
list<int> pos[MAX_PAD];
int falha[MAX_NO], output[MAX_NO], len[MAX_PAD], pai[MAX_NO], nNos;

struct ahoc {

//ahoc(): nNos(0) {}
ahoc() {nNos = 0;}

void init() {
    memset(falha, -1, sizeof(falha));
    memset(output, -1, sizeof(output));
    memset(pai, -1, sizeof(output));
    for (int i = 0; i < nNos; i++) trans[i].clear();
    patt.clear(); nNos = 1;
}

int insert_patt(char* s) {
    int i, no = 0, nPatt = patt.size();
    if (patt.count(s)) return patt[s];
    else patt.insert(make_pair(s, nPatt));
    for (i = 0; s[i]; i++) {
        int u = no;
        no = trans[no].count(s[i]) ? trans[no][s[i]] : (trans[no][s[i]] = nNos++);
        pai[no] = u;
    }
    len[nPatt] = i ? i : 1;
    return output[no] = nPatt;
}

void compile() {
    queue<int> fila;
    int filho;
    FORIT (it, ALL(trans[0])) {
        falha[filho = it->second] = 0;
        fila.push(filho);
    }
    while (!fila.empty()) {
        int atual = fila.front(); fila.pop();
        FORIT (it, ALL(trans[atual])) {
            char c = it->first; filho = it->second;
            int ret = falha[atual];
            while (ret != -1 && !trans[ret].count(c))
                ret = falha[ret];
            if (ret != -1) falha[filho] = trans[ret][c];
            else if (trans[0].count(c)) falha[filho] = trans[0][c];
            if (output[filho] == -1 && falha[filho] != -1 && output[falha[filho]] != -1)
                    output[filho] = output[falha[filho]];
            fila.push(filho);
        }
    }
}

void search(char* s) {
    int ret, atual = 0, i = 0;
    int N = patt.size();
    for (int j = 0; j < N; j++) pos[j].clear();
    do {
        while (atual != -1 && !trans[atual].count(s[i]))
            atual = falha[atual];
        atual = (atual == -1) ? 0 : trans[atual][s[i]];
        for (ret = atual; ret != -1 && output[ret] != -1; ret = falha[ret]) {
            pos[output[ret]].push_back(i - len[output[ret]] + 1);
            while (falha[ret] != -1 && output[falha[ret]] == output[ret])
                ret = falha[ret];
        }
    } while (s[i++]);
}


};


int main() {

    int T;
    char S[101010], p[1010];
    ahoc AHO;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", S);
        int Q;
        scanf("%d", &Q);
        AHO.init();
        queue<string> q;
        while (Q--) {
            scanf("%s", p);
            q.push(p);
            AHO.insert_patt(p);
        }
        AHO.compile();
        AHO.search(S);
        while (!q.empty()) {
            int u = patt[q.front()]; q.pop();
            if (!pos[u].empty()) puts("y");
            else puts("n");
        }
    }

    return 0;
}
