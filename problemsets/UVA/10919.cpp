/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int C[10101];

int id = 1;

int main() {

    int K, M;
    while (scanf("%d %d", &K, &M) && K) {
        bool ok = 1;
        int x;
        for (int i = 0; i < K; i++) {
            scanf("%d", &x);
            C[x] = id;
        }
        for (int i = 0; i < M; i++) {
            int c, r;
            scanf("%d %d", &c, &r);
            int n = 0;
            for (int i = 0; i < c; i++) {
                scanf("%d", &x);
                if (C[x] == id) n++;
            }
            if (n < r) ok = 0;
        }
        if (ok) puts("yes");
        else puts("no");
        id++;
    }

    return 0;
}
