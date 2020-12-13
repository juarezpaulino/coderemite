/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int ret = -1;
        for (int a = 1; a <= N; a++) for (int b = 1; b <= a; b++) {
            int m = a*b;
            if (m > N) break;
            if (N%m!=0) continue;
            int c = N/m;
            int A = 2*(a*b + b*c + a*c);
            if (ret == -1 || ret > A) ret = A;
        }
        printf("%d\n", ret);
    }

    return 0;
}
