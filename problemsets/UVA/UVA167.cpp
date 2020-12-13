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
#include <queue>

using namespace std;

int K;
int B[8][8];
int C[8];
int ret;

void go(int k, int v) {
    if (k == 8) { ret = max(ret,v); return; }
    for (int i = 0; i < 8; i++) {
        int r;
        for (r = 0; r < k; r++) if (abs(r-k)==abs(C[r]-i) || C[r]==i) break;
        if (r != k) continue;
        C[k] = i;
        go(k+1, v+B[k][i]);
    }
}

int main() {

    scanf("%d", &K);
    while (K--) {
        for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) scanf("%d", &B[i][j]);
        ret = 0;
        go(0,0);
        printf("%5d\n", ret);
    }

    return 0;
}
