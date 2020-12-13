/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int R, N, T = 1;
    while (scanf("%d %d", &R, &N) != EOF) {
        if (!(R|N)) break;
        R--;
        if (R/N > 26) printf("Case %d: impossible\n", T++);
        else printf("Case %d: %d\n", T++, R/N);
    }

    return 0;
}
