/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int n;
    scanf("%d", &n);
    for (int i = 2; i <= 10000; i+=n) printf("%d\n", i);

    return 0;
}
