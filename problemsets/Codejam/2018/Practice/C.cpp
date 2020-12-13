/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

const double EPS = 1E-12;
inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int N, D, Ki[1010], Si[1010];

bool check(double m) {
    for (int i = 0; i < N; i++)
        if (cmp(m,Si[i]) > 0 && cmp(D, m*(double)Ki[i]/(m-(double)Si[i])) > 0)
            return false;
    return true;
}

int main() {

    int T;
    scanf("%d",&T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &D, &N);
        for (int i = 0; i < N; i++) scanf("%d %d", Ki+i, Si+i);
        printf("Case #%d: ", t);
        double lo = 0., hi = 1E16+10;
        for (int it = 0; it < 1000; it++) {
            if (cmp(hi,lo)==0) break;
            double m = (hi+lo)/2.;
            if (check(m)) lo = m; else hi = m;
        }
        printf("%.12lf\n", (lo+hi)/2.);
    }

    return 0;
}
