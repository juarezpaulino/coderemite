/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int T;

map<string, int> mapa;
string RET[50];

int V[50];
int id;

int main() {

    cin >> T;
    while (T--) {
        string S1, S2;
        int G1, G2;
        for (int i = 0; i < 50; i++) V[i] = 1;
        id = 0;
        mapa.clear();
        for (int i = 0; i < 16; i++) {
            cin >> S1 >> S2 >> G1 >> G2;
            int P1 = (mapa.count(S1)) ? mapa[S1] : (mapa[S1] = id, RET[id] = S1, id++);
            int P2 = (mapa.count(S2)) ? mapa[S2] : (mapa[S2] = id, RET[id] = S2, id++);
            if (G1 > G2) V[P2] = 0; else V[P1] = 0;
        }
        for (int i = 0; i < id; i++) if (V[i]) cout << RET[i] << endl;
     }

    return 0;
}
