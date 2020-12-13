/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int adj[110][110];

int main() {

    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a][b] = adj[b][a] = c;
    }
    int a, b, c, ret = -1;
    for (int k = 1; k <= N; k++) for (int i = k+1; i <= N; i++) for (int j = i+1; j <= N; j++) {
        int d = adj[k][i]+adj[i][j]+adj[k][j];
        if (d > ret) { ret = d; a = k; b = i; c = j; }
    }
    printf("%d %d %d\n", a, b, c);

    return 0;
}
