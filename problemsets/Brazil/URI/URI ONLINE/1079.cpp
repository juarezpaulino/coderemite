/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int n;
    scanf("%d", &n);
    double a, b, c, m = 0.;
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf%lf", &a, &b, &c);
        m = (a*2+b*3+c*5)/10.;
        printf("%.1lf\n", m);
    }

    return 0;
}
