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

    int x, y;
    scanf("%d %d", &x, &y);
    if (y < x) swap(x,y);
    int ret = 0;
    for (int i = x; i <= y; i++) if (i%13) ret += i;
    printf("%d\n", ret);

    return 0;
}
