/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case %d: ", t);
        int N;
        scanf("%d", &N);
        int m = 0, j = 0;
        while (N--) {
            int x;
            scanf("%d", &x);
            m += (x / 30 + 1) * 10;
            j += (x / 60 + 1) * 15;
        }
        if (m < j) printf("Mile %d\n", m);
        else if (j < m) printf("Juice %d\n", j);
        else printf("Mile Juice %d\n", j);
    }

    return 0;
}
