/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    double a;
    scanf("%lf", &a);
    if (a < 400.01) printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 15 %%\n", a*1.15, a*1.15-a);
    else if (a < 800.01) printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 12 %%\n", a*1.12, a*1.12-a);
    else if (a < 1200.01) printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 10 %%\n", a*1.10, a*1.10-a);
    else if (a < 2000.01) printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 7 %%\n", a*1.07, a*1.07-a);
    else printf("Novo salario: %.2lf\nReajuste ganho: %.2lf\nEm percentual: 4 %%\n", a*1.04, a*1.04-a);

    return 0;
}
