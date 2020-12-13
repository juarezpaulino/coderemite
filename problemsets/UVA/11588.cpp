/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

char MAPA[25][25];

int main() {

    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        int R, S, M, N;
        scanf("%d %d %d %d", &R, &S, &M, &N);
        printf("Case %d: ", tc);
        for (int i = 0; i < R; i++) scanf("%s", MAPA[i]);
        int C[26] = {0};
        for (int i = 0; i < R; i++) for (int j = 0; j < S; j++) C[MAPA[i][j]-'A']++;
        int ret = -1, t = 0;
        for (int i = 0; i < 26; i++)
            if (C[i] > ret) ret = C[i], t = C[i];
            else if (C[i]==ret) t += C[i];
        ret = t*M + (R*S-t)*N;
        printf("%d\n", ret);
    }

    return 0;
}
