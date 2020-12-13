/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

int main() {
    int i, j, k, n, m, *v = 314+new int[100000];

    for (scanf("%d", &n); n-- && scanf("%d", &m); printf("%d\n", k))
        for (*v=i=(k=1)-1; i++<m; ) {
            scanf("%d", v-i);
            for (j=i; j<=i; ++j)
                v[v[-j]%k]-k ? v[v[-j]%k]=k : *(v+k++)=(j=-1)++;
        }

    return 0;
}
