/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int T; scanf("%d", &T);
    while (T--) {
        int h, m;
        scanf("%d:%d", &h, &m);
        h = 11 - h;
        if (!m) h++;
        if (h <= 0) h += 12;
        if (m != 0) m = 60-m;
        printf("%02d:%02d\n", h, m);
    }

    return 0;
}
