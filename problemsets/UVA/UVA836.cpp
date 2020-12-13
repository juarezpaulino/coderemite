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

int M, N;
char MAT[30][30];

int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        int M = 0;
        while (gets(MAT[M])) {
            if (!MAT[M][0]) break;
            M++;
        }
        for (N = 0; MAT[0][N]; N++);
        int ret = -1;
        for (int k = 0; k < M; k++) {
            int DP[30] = {0};
            for (int i = k; i < M; i++) {
                int s = 0;
                for (int j = 0; j < N; j++) {
                    if (DP[j]==-1) s = 0;
                    else if (MAT[i][j]=='0') { DP[j] = -1; s = 0; }
                    else s += ++DP[j];
                    if (s > ret) ret = s;
                }
            }
        }
        printf("%d\n", ret);
        if (T) putchar('\n');
    }

    return 0;
}
