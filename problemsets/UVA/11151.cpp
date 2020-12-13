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
int DP[1010][1010];

int go(int i, int j) {
    int &ret = DP[i][j];
    if (ret != -1) return ret;
    if (i > j) return ret = 0;
    if (i == j) return ret = 1;
    ret = 0;
    ret = max(ret, go(i+1, j));
    ret = max(ret, go(i, j-1));
    if (S[i]==S[j]) ret = 2 + go(i+1, j-1);
    return ret;
}

int main() {

    int T;
    scanf("%d", &T);
    gets(S);
    while (T--) {
        gets(S);
        if (!*S) { puts("0"); continue; }
        N = strlen(S);
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) DP[i][j] = -1;
        int ret = go(0,N-1);
        printf("%d\n", ret);
    }

    return 0;
}
