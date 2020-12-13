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

    while (1) {
        int a, b;
        scanf("%d%d", &a,&b);
        if (a <= 0 || b <= 0) break;
        if (b < a) swap(a,b);
        int ret = 0;
        for (int i = a; i <= b; i++) printf("%d ", i), ret += i;
        printf("Sum=%d\n", ret);
    }

    return 0;
}
