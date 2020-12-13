/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

using namespace std;

int main() {

    int N, M;
    scanf("%d %d ", &N, &M);
    int x = 0, y = 0, d;
    char c;
    long long M2 = M*(long long)M;
    bool ok = 1;
    while (ok && N--) {
        scanf("%c %d ", &c, &d);
        if (c == 'N') y += d;
        else if (c == 'S') y -= d;
        else if (c == 'L') x += d;
        else if (c == 'O') x -= d;
        if ((long long)x*x+(long long)y*y > M2) ok = 0;
    }
    if (ok) puts("0");
    else puts("1");

    return 0;
}
