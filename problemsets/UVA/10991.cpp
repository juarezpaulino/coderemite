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

    int T;
    scanf("%d", &T);
    while (T--) {
        double r1, r2, r3;
        scanf("%lf %lf %lf", &r1, &r2, &r3);
        double  s1 = r2+r3,
                s2 = r1+r3,
                s3 = r1+r2,
                p = (s1+s2+s3) / 2,
                total = sqrt(p*(p-s1)*(p-s2)*(p-s3)),
                alpha = acos((s2*s2+s3*s3-s1*s1) / (2*s2*s3)),
                beta = acos((s1*s1+s3*s3-s2*s2) / (2*s1*s3)),
                gamma = M_PI - alpha - beta,
                ret = total - alpha*r1*r1/2. - beta*r2*r2/2. - gamma*r3*r3/2.;
        printf("%.6lf\n", ret);
    }

    return 0;
}
