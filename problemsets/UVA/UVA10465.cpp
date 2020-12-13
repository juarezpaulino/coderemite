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

int M, N, T;

int DP[10010];

int main() {

    while (scanf("%d %d %d", &M, &N, &T) != EOF) {
        for (int i = 0; i <= T; i++) DP[i] = -0x3F3F3F3F;
        DP[0] = 0;
        for (int i = 1; i <= T; i++) {
            if (i-M >= 0 && DP[i] < DP[i-M]+1) DP[i] = DP[i-M]+1;
            if (i-N >= 0 && DP[i] < DP[i-N]+1) DP[i] = DP[i-N]+1;
        }
        int k;
        for (k = T; k && DP[k]<0; k--);
        printf("%d", DP[k]);
        if (T-k) printf(" %d", T-k);
        putchar('\n');
    }

    return 0;
}
