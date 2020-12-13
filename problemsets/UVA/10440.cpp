/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;


int main() {

    int ID;
    int N, T, M;
    int V[2020], U[2020];
    scanf("%d", &ID);
    while (ID--) {
        scanf("%d %d %d", &N, &T, &M);
        for (int i = 0; i < M; i++) scanf("%d", V+i);
        int m = 0;
        for (int i = M-1; i >= 0; i-=N) U[m++] = V[i];
        reverse(U, U+m);
        int ret = 0;
        for (int i = 0; i < m; i++) ret = max(ret + 2*T, U[i] + 2*T);
        ret -= T;
        printf("%d %d\n", ret, m);
    }

    return 0;
}
