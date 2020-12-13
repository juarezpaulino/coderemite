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
    for (int t = 1; t <= T; t++) {
        int cd, cm, cy;
        int bd, bm, by;
        scanf("%d/%d/%d %d/%d/%d", &cd, &cm, &cy, &bd, &bm, &by);
        printf("Case #%d: ", t);
        if (by > cy || (by==cy && bm > cm) || (by==cy && bm==cm && bd > cd)) puts("Invalid birth date");
        else {
            int ret = cy - by;
            if (cm < bm || (cm==bm && cd < bd)) ret--;
            if (ret > 130) puts("Check birth date");
            else printf("%d\n", ret);
        }
    }

    return 0;
}
