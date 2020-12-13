/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#define SI(A) (A.size())

#define MAXDP 2002

char A[MAXDP], B[MAXDP];
int DP[MAXDP][MAXDP], PAR[MAXDP][MAXDP];

int edit_distance(char X[], char Y[], int c[][MAXDP], int b[][MAXDP]) {
    int m = strlen(X);
    int n = strlen(Y);
    int i, j, val;
    c[0][0] = 0;
    for (i = 1; i <= m; i++) c[i][0] = i, b[i][0] = 2;
    for (j = 1; j <= n; j++) c[0][j] = j, b[i][0] = 1;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++) {
            val = (X[i-1] == Y[j-1]) ? 0 : 1;
            //delete
            if (c[i-1][j]+1 < c[i][j-1]+1) c[i][j] = c[i-1][j]+1, b[i][j] = 2;
            // insert
            else c[i][j] = c[i][j-1]+1, b[i][j] = 1;
            if (c[i-1][j-1]+val <= c[i][j]) {
                c[i][j] = c[i-1][j-1]+val;
                /* equal / change */
                (X[i-1] == Y[j-1]) ? b[i][j] = 4 : b[i][j] = 0;

            }
        }
    return (c[m][n]);
}


int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        scanf("%s %s", A, B);
        printf("%d\n", edit_distance(A,B,DP,PAR));
    }

    return 0;
}
