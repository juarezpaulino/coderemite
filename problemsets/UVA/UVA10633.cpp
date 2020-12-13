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

long long K;

int main() {

    while (scanf("%lld", &K)) {
        if (!K) break;
        bool f = false;
        long long N = K + K/9;
        for (long long n = N-10; n <= N+10; n++) {
            if (n-(n/10) == K) {
                if (f) putchar(' ');
                f = true;
                printf("%lld", n);
            }
        }
        putchar('\n');
    }

    return 0;
}
