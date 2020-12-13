/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int A[10000];

int main() {

    int Z, I, M, L;
    int c = 1;
    while (scanf("%d %d %d %d", &Z, &I, &M, &L)) {
        if (!(Z|I|M|L)) break;
        memset(A, 0, sizeof(A));
        int ret = 0;
        L = ((((Z%M)*(L%M))%M) + (I%M)) % M;
        while (!A[L]) {
            ret++;
            A[L] = 1;
            L = ((((Z%M)*(L%M))%M) + (I%M)) % M;
        }
        printf("Case %d: %d\n", c++, ret);
    }

    return 0;
}
