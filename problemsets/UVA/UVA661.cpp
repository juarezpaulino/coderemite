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

int N, M, C;
int A[25], F[25];

int main() {

    int T = 1;
    while (scanf("%d %d %d", &N, &M, &C) != EOF) {
        if (!(N|M|C)) break;
        for (int i = 1; i <= N; i++) scanf("%d", A+i), F[i] = 0;
        int ret = 0, tot = 0;
        bool f = true;
        for (int i = 0; i < M; i++) {
            int x;
            scanf("%d", &x);
            if (!F[x]) ret += A[x], F[x] = 1, tot = max(tot,ret);
            else ret -= A[x], F[x] = 0;
            if (ret > C) f = false;
        }
        printf("Sequence %d\n", T++);
        if (!f) puts("Fuse was blown.\n");
        else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", tot);
    }

    return 0;
}
