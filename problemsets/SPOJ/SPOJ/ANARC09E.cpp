/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int N;

    int id = 1;
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        if ((N*3)%2) printf("%d. %s %d\n", id++, "odd", (N*3+1)/2/3);
        else printf("%d. %s %d\n", id++, "even", (N*3)/2/3);
    }

    return 0;
}
