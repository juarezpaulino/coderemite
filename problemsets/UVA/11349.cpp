/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

long long M[1010][1010];


int main() {

    int T;
    scanf("%d", &T);
    int id = 1;
    while (T--) {
        int N;
        scanf("%*s %*s %d", &N);
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%lld", &M[i][j]);
        bool ok = 1;
        for (int i = 0; ok && i < (N+1)/2; i++) {
            for (int j = 0; j < N; j++) {
                if (M[i][j]!=M[N-1-i][N-1-j] || M[i][j] < 0) { ok = 0; break; }
            }
        }
        printf("Test #%d: ", id++);
        if (ok) puts("Symmetric.");
        else puts("Non-symmetric.");
    }

    return 0;
}
