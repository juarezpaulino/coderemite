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
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int R;
        scanf("%d", &R);
        int w = R*5;
        int h = 60*w / 100;
        int x0 = -45*w / 100;
        int y0 = -60*w / 200;
        printf("Case %d:\n", t);
        printf("%d %d\n", x0, y0+h);
        printf("%d %d\n", x0+w, y0+h);
        printf("%d %d\n", x0+w, y0);
        printf("%d %d\n", x0, y0);
    }

    return 0;
}
