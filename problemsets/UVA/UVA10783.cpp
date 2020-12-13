/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int T, A, B;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &A, &B);
        if (A%2==0) A++;
        if (B%2==0) B--;
        int ret = (A+B)*((B-A)/2+1) / 2;
        printf("Case %d: %d\n", t, ret);
    }

    return 0;
}
