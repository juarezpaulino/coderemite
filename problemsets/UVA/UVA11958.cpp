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
#include <numeric>

using namespace std;

const int MOD = 24*60;

int main() {

    int T, K;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int A, B, h, m, d;
        scanf("%d %d:%d", &K, &h, &m);
        A = h*60 + m;
        int ret = 0x3f3f3f3f;
        for (int i = 0; i < K; i++) {
            scanf("%d:%d %d", &h, &m, &d);
            B = h*60 + m;
            ret = min(ret, ((B+MOD-A)%MOD) + d);
        }
        printf("Case %d: %d\n", t, ret);
    }

    return 0;
}
