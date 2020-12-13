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

using namespace std;

char M[150][150];

int main() {

    int N = 0, K = 0;
    for (int i = 0; i < 150; i++) for (int j = 0; j < 150; j++) M[i][j] = ' ';
    while (gets(M[N])) K = max(K, (int)strlen(M[N])), M[N][strlen(M[N])] = ' ', N++;
    for (int k = 0; k < K; k++) {
        for (int i = N-1; i >= 0; i--) putchar(M[i][k]);
        putchar('\n');
    }

    return 0;
}
