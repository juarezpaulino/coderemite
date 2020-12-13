/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int ret = 0;
    double c;
    for (int i = 0; i < 6; i++) {
        scanf("%lf", &c);
        if (c > 0) ret++;
    }
    printf("%d valores positivos\n", ret);

    return 0;
}
