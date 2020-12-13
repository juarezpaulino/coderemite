/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <sstream>

using namespace std;

char R[202];
int N, V[20];

void subset_sum(int M) {
    for (int i = 0; i <= M; i++) R[i] = 0;
    R[0] = 1;
    int m = V[0];
    for (int i = 0; i < N; i++, m += V[i])
        for (int j = min(m,M); j >= V[i]; j--) if (!R[j])
            R[j] |= R[j-V[i]];
}

int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        int sum = 0;
        char S[1010];
        gets(S);
        istringstream is(S);
        N = 0;
        while (is >> V[N]) sum += V[N++];
        bool ok = 1;
        if (sum%2) ok = 0;
        else { subset_sum(sum/2); ok &= R[sum/2]; }
        if (ok) puts("YES");
        else puts("NO");
    }

    return 0;
}
