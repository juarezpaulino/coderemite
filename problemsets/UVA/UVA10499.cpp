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

int main() {

    int N;
    while (scanf("%d", &N)) {
        if (N < 0) break;
        if (N == 1) puts("0%");
        else printf("%lld%%\n", 25LL * N);
    }

    return 0;
}
