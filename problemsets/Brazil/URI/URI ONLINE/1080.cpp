/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int n, p = 1;
    scanf("%d", &n);
    for (int i = 1; i < 100; i++) {
        int x;
        scanf("%d", &x);
        if (x > n) n = x, p = i+1;
    }
    printf("%d\n%d\n", n, p);

    return 0;
}
