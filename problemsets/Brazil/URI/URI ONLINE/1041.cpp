/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;


int main() {

    double a, b;
    scanf("%lf%lf", &a, &b);
    if (fabs(a) < 1E-10 && fabs(b) < 1E-10) puts("Origem");
    else if (fabs(a) < 1E-10) puts("Eixo Y");
    else if (fabs(b) < 1E-10) puts("Eixo X");
    else if (a > 1E-10 && b > 1E-10) puts("Q1");
    else if (a < 1E-10 && b > 1E-10) puts("Q2");
    else if (a < 1E-10 && b < 1E-10) puts("Q3");
    else if (a > 1E-10 && b < 1E-10) puts("Q4");

    return 0;
}
