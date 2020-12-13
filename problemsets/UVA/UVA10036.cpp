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

int N, K;
int V[10000];
int DP[2][100];
int id = 1;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &K);
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        int k = 0;
        DP[k][abs(V[0])%K] = id++;
        while (++k < N) {
            for (int i = 0; i < K; i++) if (DP[(k-1)%2][i]==id-1) {
                DP[k%2][(i+(abs(V[k])%K))%K] = id;
                DP[k%2][(i+K-(abs(V[k])%K))%K] = id;
            }
            id++;
        }
        if (DP[(k-1)%2][0]==id-1) puts("Divisible");
        else puts("Not divisible");
        id++;
    }

    return 0;
}
