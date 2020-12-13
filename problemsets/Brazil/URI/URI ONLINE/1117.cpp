/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int c = 0;
    double m = 0.;
    while (1) {
        double x;
        scanf("%lf",&x);
        if (x >= 0. && x <= 10.) m+=x, c++;
        else puts("nota invalida");
        if (c == 2) break;
    }
    m/=2.;
    printf("media = %.2lf\n", m);

    return 0;
}
