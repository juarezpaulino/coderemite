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

    double a;
    scanf("%lf", &a);
    if (a > -1E-10 && a < 25+1E-10) puts("Intervalo [0,25]");
    else if (a > 25+1E-10 && a < 50+1E-10) puts("Intervalo (25,50]");
    else if (a > 50+1E-10 && a < 75+1E-10) puts("Intervalo (50,75]");
    else if (a > 75+1E-10 && a < 100+1E-10) puts("Intervalo (75,100]");
    else puts("Fora de intervalo");

    return 0;
}
