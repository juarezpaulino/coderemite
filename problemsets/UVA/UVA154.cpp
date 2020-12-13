/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

char MAPA[100][5];
char S[100];
map<char,int> M;

int main() {

    M['P'] = 0;
    M['G'] = 1;
    M['S'] = 2;
    M['A'] = 3;
    M['N'] = 4;
    while (1) {
        int k = 0;
        while (scanf("%s", S)) {
            if (*S == '#') return 0;
            if (*S == 'e') break;
            MAPA[k][M[S[2]]] = S[0];
            MAPA[k][M[S[6]]] = S[4];
            MAPA[k][M[S[10]]] = S[8];
            MAPA[k][M[S[14]]] = S[12];
            MAPA[k][M[S[18]]] = S[16];
            k++;
        }
        int ret = -1, b = 0x3F3F3F3F;
        for (int i = 0; i < k; i++) {
            int t = 0;
            for (int j = 0; j < k; j++) if (i != j) {
                for (int s = 0; s < 5; s++) t += MAPA[i][s]!=MAPA[j][s];
            }
            if (t < b) { b = t; ret = i+1; }
        }
        printf("%d\n", ret);
    }

    return 0;
}
