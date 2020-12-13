/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
int DP[130][20];
int adj[130][20][20];

int go(int k, int h) {
    int &ret = DP[k][h];
    if (ret != -1) return ret;
    if (k == N-1) return 0;
    ret = 1<<29;
    for (int i = 0; i < M; i++)
        ret = min(ret, adj[k][h][i]+go(k+1, i));
    ret += 2;
    return ret;
}


int main() {

    char name[50];
    while (scanf("%s", name) != EOF) {
        printf("%s\n", name);
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
            DP[i][j] = -1;
        for (int k = 0; k < N-1; k++)
            for (int i = 0; i < M; i++)
                for (int j = 0; j < M; j++) {
                    scanf("%d", &adj[k][i][j]);
        }
        int ret = 1<<29;
        for (int i = 0; i < M; i++) ret = min(ret, go(0,i));
        printf("%d\n", ret);
    }

    return 0;
}
