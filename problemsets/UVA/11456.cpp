/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int W[2020];
int LIS[2020], LDS[2020];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", W+i);
        for (int i = N-1; i >= 0; i--) {
            LIS[i] = 1; LDS[i] = 1;
            for (int j = i+1; j < N; j++)
                if (W[i] > W[j])
                    LIS[i] = max(LIS[i], LIS[j]+1);
            for (int j = i+1; j < N; j++)
                if (W[i] < W[j])
                    LDS[i] = max(LDS[i], LDS[j]+1);
        }
        int ret = 0;
        for (int i = 0; i < N; i++) ret = max(ret, LIS[i]+LDS[i]-1);
        printf("%d\n", ret);
    }

    return 0;
}
