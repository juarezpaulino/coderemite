/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>


using namespace std;


int main() {

    int id = 1;
    while (1) {
        int k; scanf("%d", &k);
        if (!k) break;
        double u, v, t, a, s;
        switch (k) {
            case 1:
                scanf("%lf %lf %lf", &u, &v, &t);
                a = (v-u) / t;
                s = u*t + a*t*t/2.;
                printf("Case %d: %.3lf %.3lf\n", id++, s, a);
                break;
            case 2:
                scanf("%lf %lf %lf", &u, &v, &a);
                t = (v-u) / a;
                s = u*t + a*t*t/2.;
                printf("Case %d: %.3lf %.3lf\n", id++, s, t);
                break;
            case 3:
                scanf("%lf %lf %lf", &u, &a, &s);
                t = (-u + sqrt(u*u + 2*a*s)) / a;
                v = u + a*t;
                printf("Case %d: %.3lf %.3lf\n", id++, v, t);
                break;
            case 4:
                scanf("%lf %lf %lf", &v, &a, &s);
                t = (-v + sqrt(v*v - 2*a*s)) / (-a);
                u = v - a*t;
                printf("Case %d: %.3lf %.3lf\n", id++, u, t);
                break;
        }
    }

    return 0;
}
