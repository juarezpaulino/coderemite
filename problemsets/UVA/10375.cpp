/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int p, q, r, s;
    while (scanf("%d %d %d %d", &p, &q, &r, &s) != EOF) {
        if (q < p-q) q = p-q;
        if (s < r-s) s = r-s;

        long double ret = 0;

        if (p > r) for (int i = r+1; i <= p; i++) ret += log(i);
        else for (int i = p+1; i <= r; i++) ret -= log(i);

        if (s > q) for (int i = q+1; i <= s; i++) ret += log(i);
        else for (int i = s+1; i <= q; i++) ret -= log(i);

        if (r-s > p-q) for (int i = p-q+1; i <= r-s; i++) ret += log(i);
        else for (int i = r-s+1; i <= p-q; i++) ret -= log(i);

        ret = exp(ret);
        printf("%.5Lf\n", ret);
    }

    return 0;
}
