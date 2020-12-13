/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

using namespace std;

int v[] = { 180000, 300000, 400000, 300000 };
double tx[] = { 0., 0.1, 0.15, 0.2, 0.25 };

int main() {

    int T, N, id = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        double tax = 0.;
        int i = 0;
        while (N > 0 && i < 4) {
            if (N <= v[i]) break;
            tax += v[i]*tx[i];
            N -= v[i];
            i++;
        }
        tax += N*tx[i];
        int ret = ceil(tax);
        if (ret && ret < 2000) ret = 2000;
        printf("Case %d: %d\n", id++, ret);
    }

    return 0;
}
