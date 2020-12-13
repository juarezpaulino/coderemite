/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

int main() {

    int M, N;
    int id = 1;
    while (scanf("%d %d ", &M, &N)) {
        if (M+N==0) break;
        char S[1010];
        for (int i = 0; i < M; i++) gets(S);
        char ret[1010];
        int k = -1, v;
        double b = 0, p;
        for (int i = 0; i < N; i++) {
            gets(S);
            scanf("%lf %d ", &p, &v);
            if (v > k || (v==k && p-b < -1E-10))
                strcpy(ret, S), k = v, b = p;
            for (int j = 0; j < v; j++) gets(S);
        }
        if (id != 1) putchar('\n');
        printf("RFP #%d\n%s\n", id++, ret);
    }

    return 0;
}
