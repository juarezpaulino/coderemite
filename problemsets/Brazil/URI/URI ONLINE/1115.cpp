/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int x, y;
    while (1) {
        scanf("%d%d",&x,&y);
        if (!x || !y) break;
        if (x > 0 && y > 0) puts("primeiro");
        else if (x < 0 && y > 0) puts("segundo");
        else if (x < 0 && y < 0) puts("terceiro");
        else if (x > 0 && y < 0) puts("quarto");
    }

    return 0;
}
