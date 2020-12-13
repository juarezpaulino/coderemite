/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int W;
        scanf("%d", &W);
        bool ok = 1;
        int ret = -1, y0, y1;
        while (W--) {
            scanf("%d %d", &y0, &y1);
            if (ret == -1) ret = abs(y0-y1);
            else if (abs(y0-y1) != ret) ok = 0;
        }
        if (ok) puts("yes");
        else puts("no");
        if (T) putchar('\n');
    }


    return 0;
}
