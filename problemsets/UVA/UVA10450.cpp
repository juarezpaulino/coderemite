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

int T, N;
long long RET[60];

int main() {

    RET[0] = 1; RET[1] = 2;
    for (int i = 2; i < 60; i++) {
        RET[i] = RET[i-1] + RET[i-2];
    }

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        printf("Scenario #%d:\n%lld\n\n", t, RET[N]);
    }

    return 0;
}
