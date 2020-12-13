/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

long long count(int v) {
    if (v <= 0) return 0;
    long long ret = 0;
    while (v) {
        ret += v/10 * 45LL;
        ret += (v%10)*(v%10+1) / 2;
        v /= 10;
    }
    return ret;
}

int main() {

    int p, q;
    while (scanf("%d %d", &p, &q)) {
        if (p < 0 && q < 0) break;
        printf("%lld\n", count(q) - count(p-1));
    }

    return 0;
}
