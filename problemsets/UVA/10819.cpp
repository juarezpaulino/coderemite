/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int DP[10202][101];
int ID[10202][101];
int id = 1;
int M, N;
int P[101], V[101];

int go(int m, int n) {
    if (n == N) {
        if (m >= 200 || M+200-m > 2000)
            return 0;
        return -1;
    }
    int &ret = DP[m][n];
    if (ID[m][n]==id) return ret;
    ret = go(m, n+1);
    if (m >= P[n]) {
        int v = go(m-P[n], n+1);
        if (v != -1)
            ret = max(ret, v + V[n]);
    }
    ID[m][n] = id;
    return ret;
}


int main() {

    while (scanf("%d %d", &M, &N) != EOF) {
        for (int i = 0; i < N; i++)
            scanf("%d %d", P+i, V+i);
        int ret = go(M+200, 0); id++;
        printf("%d\n", ret);
    }

    return 0;
}
