/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;


int ret;

void squeeze(int &n, int p) { int k = 0; for (; n % p == 0; n /= p) k++; if (k > ret) ret = k; }

void factor(int n) {
    ret = 0;

    if (n < 0) { factor(-n); return; }
    if (n < 2) { ret = 1; return; }

    squeeze(n, 2); squeeze(n, 3);

    int maxP = (int)sqrt(n)+2;
    for (int p = 5; p < maxP; p += 6) { squeeze(n, p); squeeze(n, p+2); }
    if (n > 1) ret = max(ret, 1);
}

int main() {

    int T, N;

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        factor(N);
        printf("%d\n", ret);
    }

    return 0;
}
