/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int T;
    int x, y, z;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &x, &y, &z);
        int s = (x+y)*3600/3;
        int r = x*3600 - s;
        printf("%d\n", z * r / s);
    }

    return 0;
}
