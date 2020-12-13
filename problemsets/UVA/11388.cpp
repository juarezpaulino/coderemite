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

    int G, L, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &G, &L);
        if (L%G != 0) puts("-1");
        else printf("%d %d\n", G, L);
    }

    return 0;
}
