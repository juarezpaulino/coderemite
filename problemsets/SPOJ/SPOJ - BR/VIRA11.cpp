/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>

using namespace std;

char V[1010];
// DP[A][B][C]: # solutions taking 1..A by removing piece on A with color C on Bth play.
int DP[1010][1010][2], SUM[1010][1010][2];
int N;

const int MOD = 10007;

int go(int a, int b, char c);

int sum(int a, int b1, int b2, char c) {
    if (SUM[a][1][c] == -1) {
        SUM[a][1][c] = go(a, 1, c);
        for (int i = 2; i <= a; i++) SUM[a][i][c] = (SUM[a][i-1][c] + go(a, i, c)) % MOD;
    }
    if (b1 > b2) return 0;
    if (b1 == 1) return SUM[a][b2][c];
    else return (SUM[a][b2][c] - SUM[a][b1-1][c] + MOD) % MOD;
}

int go(int a, int b, char c) {
    int &ret = DP[a][b][c];
    if (ret != -1) return ret;
    if (a == 1) return ret = (b==1 && c==1) ? 1 : 0;
    if (c == 1) return ret = sum(a-1, b, a-1, !V[a-1]);
    else return ret = sum(a-1, 1, b-1, V[a-1]);
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        char c;
        scanf(" %c", &c);
        if (c == 'P') V[i] = 1; else V[i] = 0;
    }

    memset(DP, -1, sizeof(DP));
    memset(SUM, -1, sizeof(SUM));
    int ret = 0;
    for (int i = 1; i <= N; i++) ret = (ret + go(N, i, V[N])) % MOD;
    printf("%d\n", ret);

    return 0;
}
