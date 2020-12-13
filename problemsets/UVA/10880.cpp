/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d:", t);
        int C, R;
        scanf("%d %d", &C, &R);
        if (C == R) { puts(" 0"); continue; }
        int M = C-R;
        int m = sqrt(M)+1;
        set<int> D;
        for (int i = 1; i <= m; i++) if (M%i==0) {
            if (i > R) D.insert(i);
            if (M/i > R) D.insert(M/i);
        }
        for (auto d : D) printf(" %d", d);
        putchar('\n');
    }

    return 0;
}
