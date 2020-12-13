/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int ret, X[7];
        scanf("%d %d %d %d %d %d %d", X, X+1, X+2, X+3, X+4, X+5, X+6);
        ret = 2 * accumulate(X, X+4, 0) + accumulate(X+4, X+7, 0) - *min_element(X+4, X+7);
        printf("Case %d: ", t);
        if (ret >= 180) printf("A\n");
        else if (ret >= 160) printf("B\n");
        else if (ret >= 140) printf("C\n");
        else if (ret >= 120) printf("D\n");
        else printf("F\n");
    }

    return 0;
}
