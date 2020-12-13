/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int x, y;
    scanf("%d %d", &x, &y);
    if (x > y) x^=y^=x^=y;
    int ret = 0;
    for (int i = x+1; i < y; i++) if (i%2) ret += i;
    printf("%d\n", ret);

    return 0;
}
