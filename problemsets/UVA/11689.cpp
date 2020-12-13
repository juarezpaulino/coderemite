/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a += b;
        int ret = 0;
        while (a >= c) { b = a % c; ret += a/c; a = a/c + b; }
        printf("%d\n", ret);
    }

    return 0;
}
