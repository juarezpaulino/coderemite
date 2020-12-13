/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <cstdlib>

using namespace std;

char M[14][11] =    {
                        {0,0,1,1,1,0,0,1,1,1,1},
                        {0,0,1,1,1,0,0,1,1,1,0},
                        {0,0,1,1,1,0,0,1,1,0,0},
                        {0,0,1,1,1,0,0,1,0,0,0},
                        {0,0,1,1,1,0,0,0,0,0,0},
                        {0,0,1,1,0,0,0,0,0,0,0},
                        {0,0,1,0,0,0,0,0,0,0,0},
                        {0,0,0,1,0,0,0,0,0,0,0},
                        {0,1,1,1,1,0,0,1,1,1,0},
                        {0,1,1,1,1,0,0,1,1,0,0},
                        {0,1,1,1,1,0,0,1,0,0,0},
                        {0,1,1,1,1,0,0,0,0,0,0},
                        {0,1,1,1,0,0,0,0,0,0,0},
                        {0,1,1,0,0,0,0,0,0,0,0}
                    };


int main() {

    map<char,int> mapa;
    mapa['c'] = 0; mapa['d'] = 1; mapa['e'] = 2; mapa['f'] = 3; mapa['g'] = 4; mapa['a'] = 5; mapa['b'] = 6;
    mapa['C'] = 7; mapa['D'] = 8; mapa['E'] = 9; mapa['F'] = 10; mapa['G'] = 11; mapa['A'] = 12; mapa['B'] = 13;

    char S[300];
    gets(S);
    int T = atoi(S);
    while (T--) {
        gets(S);
        char P[11] = {0}, C[11] = {0};
        for (int i = 0; S[i]; i++) {
            int u = mapa[S[i]];
            for (int j = 1; j <= 10; j++) {
                if (!P[j] && M[u][j]) C[j]++;
                P[j] = M[u][j];
            }
        }
        printf("%d", C[1]);
        for (int i = 2; i <= 10; i++) printf(" %d", C[i]);
        putchar('\n');
    }

    return 0;
}
