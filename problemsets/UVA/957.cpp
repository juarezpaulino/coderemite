/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int p[101010];

int main() {

    int Y, P;
    while (scanf("%d", &Y) != EOF) {
        scanf("%d", &P);
        for (int i = 0; i < P; i++) scanf("%d", p+i);
        int ret = 0, b = -1, e = -1;
        for (int i = 0; i < P; i++) {
            int v = p[i]+Y;
            int *u = lower_bound(p, p+P, v);
            if ((u-p)-i > ret) {
                ret = (u-p)-i;
                b = p[i];
                e = *(u-1);
            }
        }
        printf("%d %d %d\n", ret, b, e);
    }

    return 0;
}
