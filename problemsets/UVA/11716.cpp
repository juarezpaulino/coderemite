/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>


using namespace std;

int main() {

    int T;
    char MAT[101][101];
    scanf("%d ", &T);
    while (T--) {
        char S[10101];
        gets(S);
        int N = strlen(S), M = (int)(sqrt(N)+1E-10);
        if (M*M != N) puts("INVALID");
        else {
            for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) MAT[i][j] = S[i*M+j];
            for (int j = 0; j < M; j++) for (int i = 0; i < M; i++) S[j*M+i] = MAT[i][j];
            puts(S);
        }
    }

    return 0;
}
