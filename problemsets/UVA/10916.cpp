/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

using namespace std;


int main() {

    int y;
    while (scanf("%d", &y)) {
        if (!y) break;
        y -= 1960; y /= 10;
        int m = 4 << y, N = 2;
        double n = 0.;
        while (n < m+1E-10) n += log(N++) / log(2);
        printf("%d\n", N-2);
    }

    return 0;
}
