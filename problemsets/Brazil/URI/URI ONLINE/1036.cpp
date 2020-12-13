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

    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    double delta = b*b-4*a*c;
    if (delta < -1E-10) puts("Impossivel calcular");
    else if (fabs(a) < 1E-10) puts("Impossivel calcular");
    else {
        double x1 = (-b + sqrt(delta)) / (2*a);
        double x2 = (-b - sqrt(delta)) / (2*a);
        printf("R1 = %.5lf\n", x1);
        printf("R2 = %.5lf\n", x2);
    }

    return 0;
}
