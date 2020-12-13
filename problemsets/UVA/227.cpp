/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char M[5][10];

int main() {

    int T = 1;
    int y, x;
    while (1) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                M[i][j] = getchar();
                if (M[i][j]==EOF) return 0;
                if (M[i][j]==' ') y = i, x = j;
            }
            getchar();
        }
        char S[1010];
        bool legal = 1;
        bool ok = 1;
        while (ok && scanf("%s", S)) {
            for (int i = 0; S[i]; i++) {
                switch (S[i]) {
                    case '0': ok = 0; break;
                    case 'A': if (legal && y > 0) swap(M[y][x], M[y-1][x]), y = y-1; else legal = 0; break;
                    case 'B': if (legal && y < 4) swap(M[y][x], M[y+1][x]), y = y+1; else legal = 0; break;
                    case 'L': if (legal && x > 0) swap(M[y][x], M[y][x-1]), x = x-1; else legal = 0; break;
                    case 'R': if (legal && x < 4) swap(M[y][x], M[y][x+1]), x = x+1; else legal = 0; break;
                }
            }
        }
        if (T != 1) putchar('\n');
        printf("Puzzle #%d:\n", T++);
        if (!legal) puts("This puzzle has no final configuration.");
        else for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) {
            if (j == 4) printf("%c\n", M[i][j]);
            else printf("%c ", M[i][j]);
        }
        getchar();
    }

    return 0;
}
