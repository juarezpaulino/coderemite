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
    if (a < 2000.01) puts("Isento");
    else if (a < 3000.01) printf("R$ %.2lf\n", (a-2000)*0.08);
    else if (a < 4500.01) printf("R$ %.2lf\n", 1000*0.08 + (a-3000)*0.18);
    else printf("R$ %.2lf\n", 1000*0.08 + 1500*0.18 + (a-4500)*0.28);

    return 0;
}
