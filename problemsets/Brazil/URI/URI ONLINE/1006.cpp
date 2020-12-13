/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    double a, b, c, MEDIA;
    scanf("%lf %lf %lf", &a, &b, &c);
    MEDIA = (a*2+b*3+c*5)/10.;
    printf("MEDIA = %.1lf\n", MEDIA);

    return 0;
}
