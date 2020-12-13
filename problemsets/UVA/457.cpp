/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int main() {

    int T;
    int DNA[9];
    char E[4];
    map<char, int> M;
    E[0] = ' '; E[1] = '.'; E[2] = 'x'; E[3] = 'W';
    M[' '] = 0; M['.'] = 1; M['x'] = 2; M['W'] = 3;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 10; i++) scanf("%d", DNA+i);
        char D[41] = {0};
        for (int i = 0; i < 40; i++) D[i] = ' ';
        D[19] = '.';
        puts(D);
        for (int i = 0; i < 49; i++) {
            char C[41] = {0};
            for (int j = 0; j < 40; j++) {
                int s = M[D[j]];
                if (j) s += M[D[j-1]];
                if (j < 39) s += M[D[j+1]];
                C[j] = E[DNA[s]];
            }
            memcpy(D, C, sizeof(C));
            puts(D);
        }
        if (T) putchar('\n');
    }

    return 0;
}
