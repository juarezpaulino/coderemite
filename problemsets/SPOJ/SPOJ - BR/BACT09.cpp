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

    int N;
    scanf("%d", &N);
    int ret = -1;
    double v = 0;
    for (int i = 0; i < N; i++) {
        int D, C;
        double u;
        scanf("%d %d", &D, &C);
        if ((u = C*log(D)) > v) v = u, ret = i;
    }
    printf("%d\n", ret);

    return 0;
}
