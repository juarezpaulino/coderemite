/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

const int INF = 0x3F3F3F3F;

int N;

int main() {

    int A, B, a, b;
    int id = 1;
    while (scanf("%d %d", &a, &b)) {
        if (a==0 && b==0) break;
        int G[101][101];
        memset(G, INF, sizeof(G));
        N = 0;
        map<int, int> M;
        if (!M.count(a)) M[a] = N++;
        if (!M.count(b)) M[b] = N++;
        A = M[a]; B = M[b];
        G[A][B] = 1;
        while (scanf("%d %d", &a, &b)) {
            if (a==0 && b==0) break;
            if (!M.count(a)) M[a] = N++;
            if (!M.count(b)) M[b] = N++;
            A = M[a]; B = M[b];
            G[A][B] = 1;
        }
        for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            int d = G[i][k] + G[k][j];
            if (d < G[i][j]) G[i][j] = d;
        }
        double ret = 0;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (i != j) ret += G[i][j];
        ret /= N*(N-1);
        printf("Case %d: average length between pages = %.3lf clicks\n", id++, ret+1E-10);
    }

    return 0;
}
