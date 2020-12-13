/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int V[101010];
int A[2][101010];


int main() {

    int TT;
    scanf("%d", &TT);
    for (int tt = 1; tt <= TT; tt++) {
        printf("Case #%d: ", tt);

        int N;
        cin >> N;
        int K = (N+1)>>1, M = N>>1;
        for (int i = 0; i < N; i++) scanf("%d", A[i%2]+i/2);
        sort(A[0], A[0]+K);
        sort(A[1], A[1]+M);
        int ret = -1;
        for (int i = 0; i < N; i++) {
            V[i] = A[i%2][i/2];
            if (i && V[i] < V[i-1]) { ret = i-1; break; }
        }
        if (ret == -1) puts("OK");
        else printf("%d\n", ret);
    }
    return 0;
}
