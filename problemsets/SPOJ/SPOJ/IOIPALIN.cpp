/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>


using namespace std;

int DP[2][5050];
char a[5050];
string A, B;
int N;

int main() {

    scanf("%d", &N);
    scanf("%s", a);
    A = B = a; reverse(B.begin(), B.end());

    DP[0][0] = A[0]==B[0];
    for (int i = 1; i < N; i++) DP[0][i] = (DP[0][i-1] || A[i]==B[0]);
    int k = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            DP[k][j] = DP[k^1][j];
            if (j && DP[k][j-1] > DP[k][j]) DP[k][j] = DP[k][j-1];
            if (A[j]==B[i]) {
                int v = !j ? 1 : DP[k^1][j-1] + 1;
                if (v > DP[k][j]) DP[k][j] = v;
            }
        }
        k = k^1;
    }
    printf("%d\n", N - DP[k^1][N-1]);

    return 0;
}
