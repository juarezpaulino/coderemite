/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int T;
    char S[110];
    scanf("%d", &T);
    int id = 1;
    while (T--) {
        int N;
        scanf("%d", &N);
        scanf("%s", S);
        int ret = 0;
        for (int i = 0; i < N; i++) if (S[i]=='.') i += 2, ret++;
        printf("Case %d: %d\n", id++, ret);
    }

    return 0;
}
