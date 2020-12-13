/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 0x3F3F3F3F;

int VAL[110];
int REC[110][110];
int N, R;

int main() {

    while (1) {
        scanf("%d %d", &N, &R);
        if (!N && !R) break;
        for (int i = 0; i < N; i++) { scanf("%d", VAL+i); VAL[i]*=10; }
        for (int i = 0; i < R; i++) for (int j = 0; j < N; j++) scanf("%d", &REC[i][j]);

        int id = 1, tot = 0;
        for (int k = 0; k < R; k++) {
            int t = INF;
            for (int j = 0; j < N; j++) {
                if (REC[k][j] == 0) continue;
                t = min(t, VAL[j]/REC[k][j]);
            }
            if (t > tot) { id = k+1; tot = t; }
        }
        printf("%d %d\n", id, tot);
    }

    return 0;
}
