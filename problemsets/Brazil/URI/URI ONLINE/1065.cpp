/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int a;
    int ret = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &a);
        if (a%2==0) ret++;
    }
    printf("%d valores pares\n", ret);

    return 0;
}
