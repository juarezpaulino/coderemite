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

int V[100][100];
int DP[100];
int M, N;

int main() {

    while (scanf("%d %d", &M, &N)) {
        if (!(M|N)) break;
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) {
            int x;
            scanf("%d", &x);
            V[i][j] = (x == 0) ? 1 : 0;
        }
        int ret = -1;
        for (int k = 0; k < M; k++) {
            for (int j = 0; j < N; j++) DP[j] = 0;
            for (int i = k; i < M; i++) {
                int s = 0;
                for (int j = 0; j < N; j++) {
                    if (DP[j]==-1) s = 0;
                    else if (V[i][j]==0) DP[j] = -1, s = 0;
                    else s += ++DP[j];
                    ret = max(ret, s);
                }
            }
        }
        printf("%d\n", ret);
    }

    return 0;
}
