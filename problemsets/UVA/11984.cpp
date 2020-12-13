/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {

    int C, d;
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &C, &d);
        int x = 5*(9*C + 5*32  + 5*d) - 5*5*32;
        printf("Case %d: %.2lf\n", t, x / 45.);
    }

    return 0;
}
