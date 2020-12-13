/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int S, T, N;
int id = 1;

int main() {

    while (scanf("%d %d %d", &S, &T, &N)) {
        if (!(S|T|N)) break;
        printf("Case %d:\n", id++);
        for (int t = 0; t < T; t++) { for (int j = 0; j < (S+T)*N+T; j++) putchar('*'); putchar('\n'); }
        for (int n = 0; n < N; n++) {
            for (int s = 0; s < S; s++) {
                for (int t = 0; t < T; t++) putchar('*');
                for (int m = 0; m < N; m++) {
                    for (int s = 0; s < S; s++) putchar('.');
                    for (int t = 0; t < T; t++) putchar('*');
                }
                putchar('\n');
            }
            for (int t = 0; t < T; t++) { for (int j = 0; j < (S+T)*N+T; j++) putchar('*'); putchar('\n'); }
        }
        putchar('\n');
    }

    return 0;
}
