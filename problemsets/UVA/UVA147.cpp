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

double M;
long long DP[6010];

int C[] = { 2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1 };

int main() {

    while (scanf("%lf", &M)) {
        if (M < 1E-10) break;
        int m = M*100. + 1E-10;
        m /= 5;
        memset(DP, 0, sizeof(DP));
        DP[0] = 1;
        for (int i = 0; i < 11; i++) for (int j = C[i]; j <= m; j++)
            DP[j] += DP[j-C[i]];
        printf("%6.2lf%17lld\n", M, DP[m]);
    }

    return 0;
}
