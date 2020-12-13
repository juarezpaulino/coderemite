/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int N, S, s;
    scanf("%d %d", &N, &S);
    s = (N*N*N - N) / 2;
    int c = 0;
    if (S > s) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        int v = c++ + ((i == N-1) ? S-s : 0);
        if (j == 0) printf("%d", v);
        else if (j == N-1) printf(" %d\n", v);
        else printf(" %d", v);
    }
    else for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        int v = c++ + ((i == 0) ? S-s : 0);
        if (j == 0) printf("%d", v);
        else if (j == N-1) printf(" %d\n", v);
        else printf(" %d", v);
    }

    return 0;
}
