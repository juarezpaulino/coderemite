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

    int a, b;
    while (scanf("%d %d", &a, &b)) {
        if (a == -1 && b == -1) break;
        if (b < a) swap(a,b);
        int ret = min(b-a, 100-b+a);
        printf("%d\n", ret);
    }

    return 0;
}
