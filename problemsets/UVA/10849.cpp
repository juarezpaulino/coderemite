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

    int C;
    scanf("%d", &C);
    while (C--) {
        int T;
        scanf("%d", &T);
        int N;
        scanf("%d", &N);
        while (T--) {
            int r1, r2, c1, c2;
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            if ((r1==r2) && (c1==c2)) puts("0");
            else if ((r1+c1)%2 != (r2+c2)%2) printf("no move\n");
            else if (abs(r1-r2) == abs(c1-c2)) printf("1\n");
            else printf("2\n");
        }
    }

    return 0;
}
