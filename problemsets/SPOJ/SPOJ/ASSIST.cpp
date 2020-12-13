/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

typedef long long i64;

const int MAXV = 34000;

bool L[MAXV];
int V[3001], NV;
int N;

int main() {

    for (int i = 0; i < MAXV; i++) L[i] = 1;
    NV = 1;
    for (int i = 2; i < MAXV; i++) if (L[i]) {
        V[NV++] = i; if (NV > 3000) break;
        int c = 0;
        for (int j = i+1; j < MAXV; j++) if (L[j]) {
            c++;
            if (c == i) {
                L[j] = 0;
                c = 0;
            }
        }
    }

    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        printf("%d\n", V[N]);
    }

    return 0;
}
