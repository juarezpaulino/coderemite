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

    while (scanf("%d", &N)!=EOF) {
        long long ret = 1;
        if (N > 13) { puts("Overflow!"); continue; }
        if (N < 0) {
            if (N%2) puts("Overflow!");
            else puts("Underflow!");
            continue;
        }
        for (int i = 2; i <= N; i++) ret *= i;
        if (ret < 10000) { puts("Underflow!"); continue; }
        printf("%lld\n", ret);
    }

    return 0;
}
