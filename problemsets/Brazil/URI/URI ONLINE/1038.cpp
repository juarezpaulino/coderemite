/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int a, b;
    scanf("%d %d", &a, &b);
    double ret;
    if (a == 1) ret = b*4.;
    else if (a == 2) ret = b*4.5;
    else if (a == 3) ret = b*5.;
    else if (a == 4) ret = b*2.;
    else if (a == 5) ret = b*1.5;
    printf("Total: R$ %.2lf\n", ret);

    return 0;
}
