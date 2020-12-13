/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

char D[] = { 'O', 'I', 'Z', 'E', 'A', 'S', 'G', 'T', 'B', 'P' };

int main() {

    int T;
    scanf("%d ", &T);
    char S[110];
    while (T--) {
        while (gets(S) && *S) {
            for (int i = 0; S[i]; i++) if (S[i] >= '0' && S[i] <= '9') S[i] = D[S[i]-'0'];
            puts(S);
        }
        if (T) putchar('\n');
    }

    return 0;
}
