/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

int K, N;
int L[7];

typedef long long ll;

ll DP[7][7][7];

ll go(int i, int j, int v) {
    ll &ret = DP[i][j][v], a = 0, b = 0, c = 0;
    if (ret != -1) return ret;
    ret = 0;
    // there are things to go down.
    if (i+1 < K && j < L[i+1] && v+1 < N) {
        a = go(i+1, j, v+1);
        if (a == 0) return ret = 0;
    }

    if (v+1 < N) ret += go(i,j,v+1);

    if (j+1 == L[i] && v < N) ret++;


    if ()

    return ret;
}


int main() {


    while (scanf("%d", &K) != EOF) {
        for (int i = 0; i < K; i++) scanf("%d", L+i);
        scanf("%d", &N);
        for (int i = 0; i < K; i++) for (int j = 0; j < L[K-1]; j++) for (int l = 0; l < N; l++)
            DP[i][j][l] = -1;
        ll ret = go(0,0,0);
        printf("%lld\n", ret);
    }

    return 0;
}
