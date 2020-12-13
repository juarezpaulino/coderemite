/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int N, x, y;
    scanf("%d", &N);
    while (N--) {
        scanf("%d%d",&x,&y);
        if (y == 0) puts("divisao impossivel");
        else printf("%.1lf\n", x/(double)y);
    }

    return 0;
}
