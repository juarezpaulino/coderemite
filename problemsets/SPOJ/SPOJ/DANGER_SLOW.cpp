/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
///////////////////////////////////////////////////////////////////////////////
// JOSEPHUS
//
// Padrao geral - Seja K o numero para contar o proximo a sair da fila,
// a sequecia de ultimos e formada por:
// J0 = 1;
// Ji = (J(i-1) + K) % i, se Ji = 0, faca Ji = i.
//
// Para K = 2, o numero pode ser calculado iterativamente da esquerda-direita,
// fazendo swap de cada bit 0 no caminho para a esquerda. Isso corresponde a
// reduzir o numero N de 1<<di para cada posicao de 0 em di.
///////////////////////////////////////////////////////////////////////////////


#include <cstdio>
#include <cstdlib>
#include <list>
#include <string>
#include <iostream>

#define ALL(V) V.begin(), V.end()
#define ITR(V) __typeof(V.begin())

using namespace std;

string binary(int v) {
    string ret;
     while (v) { ret+='0'+(v%3); v/=3; }
    //FOR(i,0,M) { ret+='0'+(v%2); v/=2; }
    reverse(ALL(ret)); return ret;
}

int josephus2(int N) {
    int last = 0;
    list<int> F;
    for (int i = 1; i <= N; i++) F.push_back(i);
    ITR(F) it = F.begin();
    while (!F.empty()) {
        last = *it;
        for (int i = 0; i < 2; i++) {
            it++;
            if (it == F.end()) it = F.begin();
        }
        it = F.erase(it);
        if (it == F.end()) it = F.begin();
    }
    return last;
}

int main() {

    while (1) {
        int N;
        double IN;
        cin >> IN;
        N = IN+1E-10;
        if (N == 0) break;
        int ret = josephus2(N);
        cout << N << ": " << binary(N) << "    -     " << ret << ": " << binary(ret) << endl;
    }

    return 0;
}
