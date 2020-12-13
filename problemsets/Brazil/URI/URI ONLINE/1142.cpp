/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int N;
    scanf("%d", &N);
    int ret = 1;
    while (N--) {
        printf("%d %d %d PUM\n", ret, ret+1, ret+2);
        ret += 4;
    }

    return 0;
}
