/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int B, N;
int DP[1000];
int PFEE[150], PFUN[150];

int main() {

    while (1) {
        scanf("%d %d", &B, &N);
        if (B == 0 && N == 0) break;

        for (int i = 0; i < N; i++) scanf("%d %d", PFEE+i, PFUN+i);

        memset(DP,0,sizeof(DP));
        for (int i = 0; i < N; i++)
            for (int j = B; j >= PFEE[i]; j--)
                DP[j] = max(DP[j],DP[j-PFEE[i]]+PFUN[i]);

        int fee = -1, fun = -1;
        for (int i = 0; i <= B; i++)
            if (DP[i] > fun) fee = i, fun = DP[i];

        printf("%d %d\n", fee, fun);
    }

    return 0;
}
