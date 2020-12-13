/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>


using namespace std;

int main() {

    int D, I, T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &D, &I);
        int ret = 1<<(D-1);
        I--;
        for (int i = D-2; i >= 0; i--) if (I&(1<<(D-2-i))) ret += (1<<i);
        printf("%d\n", ret);
    }

    return 0;
}
