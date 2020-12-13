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

int DP[2000];
int T, N;

inline int OP(int N) {
    int ret = 0;
    while (N) { ret += (N%10)*(N%10); N/=10; }
    return ret;
}

int happy(int N) {
    if (N==1) return 1;
    if (DP[N]!=-1) return DP[N];
    DP[N] = 0;
    return DP[N] = happy(OP(N));
}

int main() {

    memset(DP,-1,sizeof(DP));

    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &N);
        printf("Case #%d: %d is %s number.\n", t, N, (happy(OP(N)) ? "a Happy" : "an Unhappy"));
    }

    return 0;
}
