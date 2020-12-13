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
        if (c == 2) {
            m/=2.;
            printf("media = %.2lf\n", m);
            while (1) {
                printf("novo calculo (1-sim 2-nao)\n");
                int y;
                scanf("%d", &y);
                if (y == 1) {
                    m = 0.; c = 0;
                    break;
                }
                else if (y == 2) return 0;
            }
        }
    }

    return 0;
}
