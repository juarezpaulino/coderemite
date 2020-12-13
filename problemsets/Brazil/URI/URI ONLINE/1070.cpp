/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int x;
    scanf("%d", &x);
    for (int i = x/2*2+1, j = 0; j < 6; i+=2, j++) printf("%d\n", i);

    return 0;
}
