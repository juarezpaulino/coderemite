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
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        a -= c, b -= d;
        a = abs(a), b = abs(b);
        a = __gcd(a,b);
        printf("%d\n", a+1);
    }

    return 0;
}
