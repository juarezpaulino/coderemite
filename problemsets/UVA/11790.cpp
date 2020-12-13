/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        vector<int> H(N,0), W(N,0),
                    LIS(N,0), LDS(N,0);
        for (int i = 0; i < N; i++) scanf("%d", &H[i]);
        for (int i = 0; i < N; i++) scanf("%d", &W[i]);
        int mLIS = 0, mLDS = 0;
        for (int i = N-1; i >= 0; i--) {
            LIS[i] = LDS[i] = W[i];
            for (int j = i+1; j < N; j++) {
                if (H[i] < H[j])
                    LIS[i] = max(LIS[i], W[i]+LIS[j]);
                if (H[i] > H[j])
                    LDS[i] = max(LDS[i], W[i]+LDS[j]);
            }
            mLIS = max(mLIS, LIS[i]);
            mLDS = max(mLDS, LDS[i]);
        }
        printf("Case %d.", t);
        if (mLIS >= mLDS) printf(" Increasing (%d). Decreasing (%d).\n", mLIS, mLDS);
        else printf(" Decreasing (%d). Increasing (%d).\n", mLDS, mLIS);
    }

    return 0;
}
