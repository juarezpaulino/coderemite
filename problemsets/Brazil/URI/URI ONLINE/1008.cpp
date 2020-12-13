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
    double s, h;
    scanf("%d%lf%lf", &n, &h, &s);
    s *= h;
    printf("NUMBER = %d\nSALARY = U$ %.2lf\n", n, s);

    return 0;
}
