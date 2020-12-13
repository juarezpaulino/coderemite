/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <sstream>
#include <map>

using namespace std;

char L[10][3][3] =  {
                        {".*","**",".."},
                        {"*.","..",".."},
                        {"*.","*.",".."},
                        {"**","..",".."},
                        {"**",".*",".."},
                        {"*.",".*",".."},
                        {"**","*.",".."},
                        {"**","**",".."},
                        {"*.","**",".."},
                        {".*","*.",".."}
                    };

map<int,char> M;

int main() {

    M[(1<<4)+(3<<2)+(0)] = '0';
    M[(2<<4)+(0<<2)+(0)] = '1';
    M[(2<<4)+(2<<2)+(0)] = '2';
    M[(3<<4)+(0<<2)+(0)] = '3';
    M[(3<<4)+(1<<2)+(0)] = '4';
    M[(2<<4)+(1<<2)+(0)] = '5';
    M[(3<<4)+(2<<2)+(0)] = '6';
    M[(3<<4)+(3<<2)+(0)] = '7';
    M[(2<<4)+(3<<2)+(0)] = '8';
    M[(1<<4)+(2<<2)+(0)] = '9';

    int D;
    while (scanf("%d", &D)) {
        if (!D) break;
        char c;
        scanf(" %c ", &c);
        if (c == 'S') {
            char ret[3][1010];
            char S[1010];
            scanf("%s", S);
            int k = 0;
            for (int l = 0; S[l]; l++) {
                if (l != 0) ret[0][k] = ret[1][k] = ret[2][k] = ' ', k++;
                for (int j = 0; j < 2; j++, k++) for (int i = 0; i < 3; i++)
                    ret[i][k] = L[S[l]-'0'][i][j];
            }
            for (int i = 0; i < 3; i++) {
                ret[i][k] = 0;
                puts(ret[i]);
            }
        }
        else {
            int ret[D]; for (int i = 0; i < D; i++) ret[i] = 0;
            char S[1010];
            for (int i = 0; i < 3; i++) {
                gets(S);
                istringstream is(S);
                int k = 0;
                while (is >> S) {
                    ret[k] = (ret[k]<<2) + (S == string("**") ? 3 : S == string("*.") ? 2 : S == string(".*") ? 1 : 0);
                    k++;
                }
            }
            for (int i = 0; i < D; i++) S[i] = M[ret[i]];
            S[D] = 0;
            puts(S);
        }
    }

    return 0;
}
