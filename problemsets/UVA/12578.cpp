/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>

using namespace std;

const double PI = 2*acos(0);


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int L;
        scanf("%d", &L);
        double w = L*6./10.;
        double r = L/5.;
        double a = PI*r*r;
        printf("%.2lf %.2lf\n", a, L*w-a);
    }

    return 0;
}
