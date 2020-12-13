/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

#define SQR(A) (A)*(A)

int main() {

    double A[3];
    scanf("%lf%lf%lf", A, A+1, A+2);
    sort(A, A+3, greater<int>());
    double d = SQR(A[1])+SQR(A[2]);
    double c = SQR(A[0]);
    if (A[0]-A[1]-A[2] > -1E-10) puts("NAO FORMA TRIANGULO");
    if (fabs(c - d) < 1E-10) puts("TRIANGULO RETANGULO");
    if (c > d) puts("TRIANGULO OBTUSANGULO");
    if (c < d) puts("TRIANGULO ACUTANGULO");
    if (fabs(A[0]-A[1]) < 1E-10 && fabs(A[0]-A[2]) < 1E-10) puts("TRIANGULO OBTUSANGULO");
    if (fabs(A[1]-A[2]) < 1E-10 || fabs(A[0]-A[1]) < 1E-10) puts("TRIANGULO ISOSCELES");

    return 0;
}
