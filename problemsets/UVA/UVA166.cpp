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

int C[6];
int S[110];
int V[] = {1,2,4,10,20,40};
int T;
int B[110][6];
int DP[110];

int main() {

    S[0] = 0;
    for (int i = 1; i <= 100; i++) {
        S[i] = 300;
        for (int j = 0; j < 6; j++) if (i-V[j]>=0)
            S[i] = min(S[i], S[i-V[j]]+1);
    }

    while (scanf("%d %d %d %d %d %d", C, C+1, C+2, C+3, C+4, C+5)) {
        if (!accumulate(C,C+6,0)) break;
        int x, y;
        scanf("%d.%d", &x, &y);
        T = (x*100+y)/5;
        DP[0] = 0;
        copy(C, C+6, &B[0][0]);
        for (int i = 1; i <= 100; i++) {
            DP[i] = 300;
            for (int j = 0; j < 6; j++) if (i-V[j] >= 0 && B[i-V[j]][j]) {
                if (DP[i] > DP[i-V[j]]+1) {
                    copy(&B[i-V[j]][0], &B[i-V[j]][6], C);
                    DP[i] = DP[i-V[j]]+1;
                    if (i > T) DP[T] = min(DP[T], DP[i]+S[i-T]);
                    C[j]--;
                    copy(C,C+6,&B[i][0]);
                }
            }
        }
        printf("%3d\n", DP[T]);
    }

    return 0;
}
