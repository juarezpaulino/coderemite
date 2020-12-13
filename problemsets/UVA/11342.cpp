/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

using namespace std;

int RET[50505][3];

int main() {

    for (int i = 0, a; (a = i*i) <= 50000; i++) for (int j = i, b; (b = a+j*j) <= 50000; j++) for (int z = j, c; (c = b+z*z) <= 50000; z++)
        if (!RET[c][2]) RET[c][0] = i, RET[c][1] = j, RET[c][2] = z;

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        if (!RET[N][2]) puts("-1");
        else printf("%d %d %d\n", RET[N][0], RET[N][1], RET[N][2]);
    }

    return 0;
}
