/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

using namespace std;

int N, B;
int b[100], u[100];

int main() {

    while (1) {
        scanf("%d %d", &N, &B);
        if (!N && !B) break;
        for (int i = 0; i < B; i++) scanf("%d", b+i);
        memset(u,0,sizeof(u));
        for (int i = 0; i < B; i++)
            for (int j = 0; j < B; j++)
                u[abs(b[i]-b[j])] = 1;
        bool ok = true;
        for (int i = 0; i <= N; i++) if (!u[i]) ok = false;
        if (ok) puts("Y");
        else puts("N");
    }

    return 0;
}
