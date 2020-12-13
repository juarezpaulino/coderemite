/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    double a, b, c, d, e;
    scanf("%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e);
    double m = a*2+b*3+c*4+d;
    m /= 10;
    printf("Media: %.1lf\n", m);
    if (m > 7.-1E-10) printf("Aluno aprovado.\n");
    else if (m < 5.-1E-10) printf("Aluno reprovado.\n");
    else {
        printf("Aluno em exame.\n");
        m = (m+e)/2.;
        printf("Nota do exame: %.1lf\n", e);
        if (m > 5.-1E-10) printf("Aluno aprovado.\n");
        else printf("Aluno reprovado.\n");
        printf("Media final: %.1lf\n", m);
    }


    return 0;
}
