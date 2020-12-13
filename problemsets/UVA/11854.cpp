/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {

    int a, b, c;
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (!(a|b|c)) break;
        if (b > a) swap(a, b);
        if (c > a) swap(a, c);
        if (b*b + c*c == a*a) puts("right");
        else puts("wrong");
    }

    return 0;
}
