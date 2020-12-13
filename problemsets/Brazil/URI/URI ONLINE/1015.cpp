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

    double a, b, c, d;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    printf("%.4lf\n", sqrt((a-c)*(a-c)+(b-d)*(b-d)));

    return 0;
}
