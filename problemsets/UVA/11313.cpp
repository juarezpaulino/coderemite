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

    int N, M, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        int ret = 0, v;
        while (N >= M) {
            ret += (v = N/M);
            N = v + (N%M);
        }
        if (N <= 1) printf("%d\n", ret);
        else printf("cannot do this\n");
    }

    return 0;
}
