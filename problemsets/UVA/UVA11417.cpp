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

int GCD[501][501];

int main() {

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        int ret = 0;
        for (int i = 1; i < N; i++) for (int j = i+1; j <= N; j++) {
            if (!GCD[i][j]) GCD[i][j] = __gcd(i,j);
            ret += GCD[i][j];
        }
        printf("%d\n", ret);
    }

    return 0;
}
