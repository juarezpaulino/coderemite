/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <map>
#include <list>
#include <queue>
#include <string>
#include <set>
#include <iostream>

using namespace std;

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")
#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-13;

_inline(int cmp)(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}


////////////////////////////////////////////////////////////////////////////////
// Aho-Corasick ////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

const int MAX_NO = 350000;
const int MAX_PAD = 75000;

typedef map<char, int> mapach;
typedef map<string, int> mapastr;


int trans[MAX_NO][11];
mapastr pad;
list<int> pos[MAX_PAD];
int falha[MAX_NO], final[MAX_NO], tam[MAX_PAD], numNos;
list<string> dic[MAX_PAD];
set<string> saida;
int m;


//////////////////////////////////////////////////////////////////////////////
// Função de inicialização.
//
// Uma chamada por instância, antes de todas as outras funções.
//
void inic() {
    memset(falha, NULO, sizeof(falha));
    memset(final, NULO, sizeof(final));
    for (int i = 1; i < 11; i++) trans[0][i] = -1;
    pad.clear(); numNos = 1;
}

//////////////////////////////////////////////////////////////////////////////
// Função que adiciona um padrão ao autômato reconhecedor.
//
// Uma chamada por padrão, depois da inicialização.
// Retorna o índice de acesso a variável global pos.
//
int adiciona_padrao(char* s) {
    int i, no = 0, numPad = pad.size();
    if (pad.count(s)) return pad[s];
    else pad.insert(make_pair(s, numPad));
    for (i = 0; s[i]; i++) {
        if (trans[no][s[i]] == -1) {
            trans[no][s[i]] = numNos;
            for (int j = 1; j < 11; j++) trans[numNos][j] = -1;
            numNos++;
        }
        no = trans[no][s[i]];
    }
    tam[numPad] = i ? i : 1;
    return final[no] = numPad;
}

//////////////////////////////////////////////////////////////////////////////
// Função que gera o tratamento de falhas.
//
// Uma chamada por instância, depois da adição de todos os padrões.
//
void gera_falhas() {
    queue<int> fila;
    int filho;
    for (int i = 1; i < 11; i++) {
        if (trans[0][i] == -1) continue;
        falha[filho = trans[0][i]] = 0;
        fila.push(filho);
    }
    while (!fila.empty()) {
        int atual = fila.front(); fila.pop();
        for (int i = 1; i < 11; i++) {
            if (trans[atual][i] == -1) continue;    
            char c = i; filho = trans[atual][i]; int ret = falha[atual];
            while (ret != NULO && trans[ret][c] == -1)
                ret = falha[ret];
            if (ret != NULO) {
                falha[filho] = trans[ret][c];
                if (final[filho] == NULO && final[falha[filho]] != NULO)
                    final[filho] = final[falha[filho]];
            } else if (trans[0][c] != -1) falha[filho] = trans[0][c];
            fila.push(filho);
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
// Função que busca os padrões em uma cadeia de consulta.
//
// Uma chamada por consulta, depois da geração do tratamento de falhas.
// Preenche a variável global pos.
//
void consulta(char* s) {
    int ret, atual = 0, i = 0;
    int N = strlen(s);
    for (int j = 0; j <= N; j++) pos[j].clear();
    do {
        while (atual != NULO && trans[atual][s[i]] == -1)
            atual = falha[atual];
        atual = (atual == NULO) ? 0 : trans[atual][s[i]];
        for (ret = atual; ret != NULO && final[ret] != NULO; ret = falha[ret]) {
            pos[i - tam[final[ret]] + 1].push_back(final[ret]);
            while (falha[ret] != NULO && final[falha[ret]] == final[ret])
                ret = falha[ret];
        }
    } while (s[i++]);
}

void seq(char *num, int p, char *out, int k) {
    int i, j;
    if (p == m) { out[k-1] = 0; saida.insert(out); }
    if (pos[p].size()) {
        foreach(it, all(pos[p])) {
            foreach(it1, all(dic[*it])) {
                string s = *it1;
                for (i = 0; i < it1->size(); i++) out[k+i] = s[i];
                out[k+i] = ' ';
                seq(num, p+tam[*it], out, k+i+1);
            }
        }
        return;
    }
    else if (k && out[k-2]>='0' && out[k-2]<='9') return;
    out[k] = num[p]+'0'-1; out[k+1] = ' ';
    seq(num, p+1, out, k+2);
}


int main() {

    int n, t;
    int i, j, p, k = 1;
    char str[200], num[200], out[200], c;
    int code[] = {5,7,6,3,0,4,9,9,6,1,7,8,5,1,8,8,1,2,3,4,7,6,2,2,3,9};
    
    while (scanf("%d ", &n) != EOF) {
        if (!n) break;
        inic();
        for (i = 0; i < n; i++) { 
            gets(str);
            for (j=p=0; str[j]; j++) {
                if (str[j]=='-' || str[j]=='\"') continue;
                c = str[j]; 
                if (c>='A' && c<='Z') num[p++] = code[c-'A']+1;
                else num[p++] = code[c-'a']+1;
            }
            num[p] = 0;
            p = adiciona_padrao(num);
            dic[p].push_back(str);
        }
        gera_falhas();
        printf("Instancia %d\n", k++);
        scanf("%d ", &t);
        for (i = 0; i < t; i++) {
            gets(str);
            for (j=p=0; str[j]; j++) { 
                if (str[j]=='-' || str[j]=='/') continue;
                num[p++] = str[j]-'0'+1;
            }
            num[p] = 0;
            m = p;
            consulta(num);
            saida.clear();
            seq(num, 0, out, 0);
            foreach(it, all(saida)) {
                printf("%s: ", str);
                for (j = 0; j != (*it).size(); j++) putchar((*it)[j]);
                putchar('\n');
            }
        }
        putchar('\n');
        for (i = 0; i < pad.size(); i++) dic[i].clear();
    }

    return 0;
}
