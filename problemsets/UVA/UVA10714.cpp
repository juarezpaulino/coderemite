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

int L, N;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &L, &N);
        int mini = 0, maxi = 0;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            mini = max(mini, min(x, L-x));
            maxi = max(maxi, max(x, L-x));
        }
        printf("%d %d\n", mini, maxi);
    }

    return 0;
}
