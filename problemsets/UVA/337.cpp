/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char M[15][15];

int main() {

    int N;
    int T = 1;
    char S[1010];
    while (gets(S)) {
        N = atoi(S);
        if (!N) break;
        for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) M[i][j] = ' ';
        int y = 0, x = 0;
        bool over = 1;
        for (int i = 0; i < N; i++) {
            gets(S);
            int j = 0;
            while (S[j]) {
                if (S[j]=='^') {
                    j++;
                    if (S[j]=='b') x = 0;
                    else if (S[j]=='c') { for (int ii = 0; ii < 10; ii++) for (int jj = 0; jj < 10; jj++) M[ii][jj] = ' '; }
                    else if (S[j]=='d') { if (y < 9) y++; }
                    else if (S[j]=='e') { for (int jj = x; jj < 10; jj++) M[y][jj] = ' '; }
                    else if (S[j]=='h') { y = 0; x = 0; }
                    else if (S[j]=='i') { over = 0; }
                    else if (S[j]=='l') { if (x > 0) x--; }
                    else if (S[j]=='o') { over = 1; }
                    else if (S[j]=='r') { if (x < 9) x++; }
                    else if (S[j]=='u') { if (y > 0) y--; }
                    else if (S[j]=='^') {
                        if (over) M[y][x++] = S[j];
                        else {
                            for (int k = 9; k > x; k--) M[y][k] = M[y][k-1];
                            M[y][x++] = S[j];
                        }
                        if (x > 9) x = 9;
                    }
                    else { y = S[j++]-'0'; x = S[j]-'0'; }
                    j++;
                }
                else {
                    if (over) M[y][x++] = S[j++];
                    else {
                        for (int k = 9; k > x; k--) M[y][k] = M[y][k-1];
                        M[y][x++] = S[j++];
                    }
                    if (x > 9) x = 9;
                }
            }
        }
        printf("Case %d\n", T++);
        puts("+----------+");
        for (int i = 0; i < 10; i++) {
            putchar('|');
            printf("%s", M[i]);
            putchar('|');
            putchar('\n');
        }
        puts("+----------+");
    }

    return 0;
}
