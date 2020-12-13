/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int W, H;
        int x, y;
        int X[10], Y[10];
        int k;
        scanf("%d %d %d %d %d", &W, &H, &x, &y, &k);
        for (int i = 0; i < k; i++) scanf("%d %d", X+i, Y+i);
        int P[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int ret = 1000000000;
        do {
            int v = 0;
            int j = x, i = y;
            for (int l = 0; l < k; l++) {
                v += abs(j-X[P[l]]) + abs(i-Y[P[l]]);
                j = X[P[l]]; i = Y[P[l]];
            }
            v += abs(j-x) + abs(i-y);
            ret = min(ret, v);
        } while (next_permutation(P, P+k));
        printf("The shortest path has length %d\n", ret);
    }

    return 0;
}
