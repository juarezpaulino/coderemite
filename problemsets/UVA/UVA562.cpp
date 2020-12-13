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

char R[25010];
int V[110];
int N;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        int t = 0;
        for (int i = 0; i < N; i++) scanf("%d", V+i), t += V[i];
        int M = t/2;
        for (int i = 0; i <= M; i++) R[i] = 0;
        R[0] = 1;
        int m = V[0];
        for (int i = 0; i < N; i++, m += V[i]) for (int j = min(m,M); j >= V[i]; j--) if (!R[j])
            R[j] |= R[j-V[i]];
        int i;
        for (i = M; i >= 0; i--) if (R[i]) break;
        printf("%d\n", t-2*i);
    }

    return 0;
}
