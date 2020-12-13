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
#include <set>
#include <queue>

using namespace std;

int k, x, y;
int ret;

void go(int cy, int cx, int k) {
    if (x >= cx-k && x <= cx+k && y >= cy-k && y <= cy+k) ret++;
    if (k == 1) return;
    go(cy-k, cx-k, k/2);
    go(cy-k, cx+k, k/2);
    go(cy+k, cx-k, k/2);
    go(cy+k, cx+k, k/2);
}

int main() {

    while (scanf("%d %d %d", &k, &x, &y)) {
        if (!(k|x|y)) break;
        ret = 0;
        go(1024, 1024, k);
        printf("%3d\n", ret);
    }

    return 0;
}
