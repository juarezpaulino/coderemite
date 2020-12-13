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

char S[1010];
int N;
bool pal[1010][1010];

int main() {

    while (scanf("%s", S) != EOF) {
        N = strlen(S);
        memset(pal,0,sizeof(pal));
        for (int k = 0; k < N; k++) pal[k][k] = 1;
        for (int k = 2; k <= N; k++) {
            for (int i = k-1; i < N; i++) {
                pal[i-k+1][i] = (k==2 || pal[i-k+2][i-1]) && (S[i-k+1]==S[i]);
            }
        }
        int ret = 0;
        for (int i = 0; i < N; i++) for (int j = i; j < N; j++) ret += pal[i][j];
        printf("%d\n", ret);
    }

    return 0;
}
