/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

using namespace std;

bool ok;

int go() {
    int wl, dl, wr, dr;
    scanf("%d %d %d %d", &wl, &dl, &wr, &dr);
    if (wl == 0) wl = go();
    if (wr == 0) wr = go();
    if (wl*dl != wr*dr) ok = 0;
    return wl + wr;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        ok = 1;
        go();
        if (ok) puts("YES");
        else puts("NO");
        if (T) putchar('\n');
    }

    return 0;
}
