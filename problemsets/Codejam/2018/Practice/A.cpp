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

int main() {

    setbuf(stdout, NULL);

    char S[100];
    int T;
    gets(S);
    sscanf(S, "%d", &T);
    while (T--) {
        int A, B, N;
        gets(S);
        sscanf(S, "%d %d", &A, &B);
        gets(S);
        sscanf(S, "%d", &N);
        for (int i = 0; i < N; i++) {
            int C = A + (B-A) / 2;

            printf("%d\n", C);
            gets(S);
            if (S[0]=='C') break;
            else if (S[4]=='S') A = C+1;
            else if (S[4]=='B') B = C;
            else return 1;
        }
    }

    return 0;
}
