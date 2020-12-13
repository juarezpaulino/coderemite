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
int A[30], B[30], Y[30];

int main() {

    int T = 1;
    while (scanf("%d", &N) != EOF) {
        if (!N) break;
        int ret = 0;
        for (int i = 0; i < N; i++) { scanf("%d%d%d", Y+i, A+i, B+i); ret = max(ret, A[i]); }
        while (ret < 10000) {
            bool ok = 1;
            for (int i = 0; ok && i < N; i++) if (((ret-A[i])%(B[i]-A[i])) + A[i] != Y[i]) ok = 0;
            if (ok) break;
            ret++;
        }
        if (ret == 10000) printf("Case #%d:\nUnknown bugs detected.\n\n", T++);
        else printf("Case #%d:\nThe actual year is %d.\n\n", T++, ret);
    }

    return 0;
}
