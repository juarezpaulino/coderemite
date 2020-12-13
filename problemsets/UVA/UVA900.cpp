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
long long FIB[55];

int main() {

    FIB[1] = 1LL; FIB[2] = 2LL;
    for (int i = 3; i <= 50; i++) FIB[i] = FIB[i-1]+FIB[i-2];

    while (scanf("%d", &N)) {
        if (!N) break;
        printf("%lld\n", FIB[N]);
    }

    return 0;
}
