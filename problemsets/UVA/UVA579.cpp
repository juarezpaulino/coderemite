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

    int H, M;
    while (scanf("%d:%d", &H, &M)) {
        if (!(H|M)) break;
        double h, m;
        h = H * 30. + (M / 60.) * 30.;
        m = M * 6.;
        double ret = abs(h-m);
        if (ret > 180) ret = 360 - ret;
        printf("%.3lf\n", ret);
    }

    return 0;
}
