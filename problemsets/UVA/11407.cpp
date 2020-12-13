/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int DP[10101];

int go(int k) {
    if (k == 0) return 0;
    int &ret = DP[k];
    if (ret != 0) return ret;
    ret = 1<<30;
    for (int i = 1, d; (d = i*i) <= k; i++) ret = min(ret, 1+go(k-d));
    return ret;
}


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int ret = go(N);
        printf("%d\n", ret);
    }

    return 0;
}
