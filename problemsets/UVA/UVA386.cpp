/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <queue>

using namespace std;

#define CUB(a) ((a)*(a)*(a))

int main() {

    int a3, b3, c3, d3;
    for (int a = 2; a <= 200; a++) {
        a3 = CUB(a);
        for (int b = 2; (b3 = CUB(b)) <= a3; b++)
        for (int c = b; b3+(c3 = CUB(c)) <= a3; c++)
        for (int d = c; b3+c3+(d3 = CUB(d)) <= a3; d++)
        if (a3==b3+c3+d3)
            printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
    }

    return 0;
}
