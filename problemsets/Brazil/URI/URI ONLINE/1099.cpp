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

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (b < a) swap(a,b);
        int ret = 0;
        for (int i = a+1; i < b; i++) if (i%2) ret += i;
        printf("%d\n", ret);
    }

    return 0;
}
