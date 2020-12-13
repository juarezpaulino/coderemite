/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {

    int T, N;
    int V[1010];
    scanf("%d", &T);
    while (T--) {
        double ret = 0, m = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", V+i), m += V[i];
        m /= N;
        for (int i = 0; i < N; i++) if (V[i]-1E-15 > m) ret++;
        printf("%.3lf%%\n", ret*100./N);
    }

    return 0;
}
