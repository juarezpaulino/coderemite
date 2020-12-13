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

const int INF = 0x3F3F3F3F;

int num;

void printMCM(int P[][20], int i, int j) {
    if (i == j) printf("A%d", num++);
    else {
        printf("(");
        printMCM(P, i, P[i][j]);
        printf(" x ");
        printMCM(P, P[i][j]+1, j);
        printf(")");
    }
}

void MCM(int M[], int N) {
    int C[20][20] = {0};
    int P[20][20] = {0};
    for (int L = 2; L <= N; L++)
        for (int i = 0; i <= N-L; i++) {
            int j = i+L-1;
            C[i][j] = INF;
            for (int k = i; k < j; k++) {
                int c = C[i][k] + C[k+1][j] + M[i]*M[k+1]*M[j+1];
                if (c < C[i][j]) { C[i][j] = c; P[i][j] = k; }
            }
        }
    num = 1;
    printMCM(P, 0, N-1);
}

int N;
int M[20];

int main() {

    int T = 1;
    while (scanf("%d", &N)) {
        if (!N) break;
        scanf("%d %d", M, M+1);
        for (int i = 1; i < N; i++) scanf("%*d %d", M+i+1);
        printf("Case %d: ", T++);
        MCM(M, N);
        putchar('\n');
    }

    return 0;
}
