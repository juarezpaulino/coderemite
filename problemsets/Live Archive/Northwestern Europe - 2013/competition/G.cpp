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
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }


int main() {

    int x, y, z;

    while (scanf("%d %d %d", &x, &y, &z) != EOF) {
        int w = x*y, u = z-y;
        int d = gcd(w,u);
        printf("%d/%d\n", w/d, u/d);
    }

    return 0;
}
