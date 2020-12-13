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

int N;

int main() {

    bool f = false;
    while (scanf("%d", &N) != EOF) {
        if (f) putchar('\n');
        f = true;
        int p = 4 + (N-1) * 8;
        int c = 0;
        for (int i = 1; i <= N-1; i++) c += sqrt((N-.5)*(N-.5) - i*i);
        c *= 4;
        printf("In the case n = %d, %d cells contain segments of the circle.\n", N, p);
        printf("There are %d cells completely contained in the circle.\n", c);
    }

    return 0;
}
