/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if (a+b > c && b+c > a && a+c > b) printf("Perimetro = %.1lf\n", a+b+c);
    else printf("Area = %.1lf\n", (a+b)*c/2.);


    return 0;
}
