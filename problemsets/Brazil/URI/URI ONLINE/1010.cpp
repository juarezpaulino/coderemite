/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    double a, b, c, d;
    scanf("%*d%lf%lf%*d%lf%lf", &a, &b, &c, &d);
    printf("VALOR A PAGAR: R$ %.2lf\n", a*b+c*d);

    return 0;
}
