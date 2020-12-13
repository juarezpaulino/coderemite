/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int I, W;

    while (1) {
        scanf("%d %d", &I, &W);
        if (I == -1 && W == -1) break;
        if (I%1000==0 && W%37==0 && I/1000==W/37) puts("Y");
        else puts("N");
    }

    return 0;
}
