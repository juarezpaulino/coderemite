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

    double n, p, k;

    while (scanf("%lf %lf", &n, &p) != EOF) {
        k = pow(10, log10(p) / n);
        printf("%.0lf\n", k);
    }

    return 0;
}
