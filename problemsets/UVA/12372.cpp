/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int L, W, H, T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d%d%d", &L, &W, &H);
        if (L > 20 || W > 20 || H > 20) printf("Case %d: bad\n", t);
        else printf("Case %d: good\n", t);
    }

    return 0;
}
