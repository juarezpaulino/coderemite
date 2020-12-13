/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    char M[510][510];
    int N;
    scanf("%d", &N);
    bool ok = 0;
    while (N--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (M[x][y]) { ok = 1; break; }
        M[x][y] = 1;
    }
    if (ok) puts("1");
    else puts("0");

    return 0;
}
