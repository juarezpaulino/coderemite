/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {

    int a, b, c, d, L;
    while (scanf("%d %d %d %d %d", &a, &b, &c, &d, &L) != EOF) {
        if (!(a|b|c|d|L)) break;
        int ret = 0;
        for (int i = 0; i <= L; i++) if ((a*i*i+b*i+c) % d == 0) ret++;
        printf("%d\n", ret);
    }

    return 0;
}
