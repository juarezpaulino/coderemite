/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        int ret = 0, x;
        for (int i = 0; i < N; i++) {
            scanf("%d", &x);
            ret ^= x;
        }
        if (ret) puts("Yes"); else puts("No");
    }

    return 0;
}
