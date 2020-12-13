/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int X, t = 1;
    while (scanf("%d", &X)) {
        if (X < 0) break;
        int ret = 0;
        while (1<<ret < X) ret++;
        printf("Case %d: %d\n", t, ret);
        t++;
    }

    return 0;
}
