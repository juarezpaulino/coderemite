/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

int main() {

    int W, N;
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d ", &W, &N);
        int way[W][N];
        char S[1010];
        memset(way,0,sizeof(way));
        for (int i = 0; i < W; i++) {
            gets(S);
            istringstream is(S);
            int j, k;
            is >> j;
            while (is >> k) way[j-1][k-1] = -1;
        }
        way[0][0] = 1;
        for (int i = 0; i < W; i++) for (int j = 0; j < N; j++) {
            if (!(i+j)) continue;
            if (way[i][j]==-1) { way[i][j] = 0; continue; }
            if (i > 0) way[i][j] += way[i-1][j];
            if (j > 0) way[i][j] += way[i][j-1];
        }
        printf("%d\n", way[W-1][N-1]);
        if (T) putchar('\n');
    }

    return 0;
}
