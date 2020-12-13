/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int D, N, K;
bool OPEN[40];
int DP[40][40];

int go(int a, int b) {
    if (b < a) return 1;
    int &ret = DP[a][b];
    if (ret != -1) return ret;
    if ((b-a+1) % 2) return ret = 0;
    ret = 0;
    for (int i = a+1; i <= b; i++) if (!OPEN[i]){
        ret += go(a+1,i-1) * go(i+1,b);
    }
    return ret;
}

int main() {

    scanf("%d", &D);
    while (D--) {
        scanf("%d %d", &N, &K); N*=2;
        memset(OPEN,0,sizeof(OPEN));
        for (int i = 0; i < K; i++) {
            int x; scanf("%d", &x);
            OPEN[x-1] = 1;
        }

        memset(DP,-1,sizeof(DP));
        int ret = go(0,N-1);
        printf("%d\n", ret);
    }

    return 0;
}
