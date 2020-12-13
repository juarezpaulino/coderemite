/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    double s, t;
    scanf("%*s%lf%lf", &s, &t);
    s += t*.15;
    printf("TOTAL = R$ %.2lf\n", s);

    return 0;
}
