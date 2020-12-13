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

long long FIB[50];

const long long LAST = 0xFFFFFFFFLL;

int main() {

    FIB[1] = FIB[2] = 1LL;
    for (int i = 3; FIB[i-1] <= LAST; i++) FIB[i] = FIB[i-1]+FIB[i-2];

    int N;
    while (scanf("%d", &N)) {
        if (N < 0) break;
        printf("%lld %lld\n", FIB[N+2]-1, FIB[N+3]-1);
    }

    return 0;
}
