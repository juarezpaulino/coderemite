/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int V[10], id = 1;

int main() {

    int M, N;
    while (scanf("%d %d", &M, &N) != EOF) {
        int ret = 0;
        for (int i = M; i <= N; i++) {
            bool ok = 1;
            int k = i;
            while (k) { if (V[k%10] == id) { ok = 0; break; } V[k%10] = id; k /= 10; }
            id++;
            ret += ok;
        }
        printf("%d\n", ret);
    }

    return 0;
}
