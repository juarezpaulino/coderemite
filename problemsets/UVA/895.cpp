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
#include <algorithm>

using namespace std;

char D[1000][30], W[30];

int main() {

    int N = 0;
    char S[1010];
    while (gets(S)) {
        if (*S=='#') break;
        for (int i = 0; S[i]; i++) D[N][S[i]-'a']++;
        N++;
    }
    while (gets(S)) {
        if (*S=='#') break;
        memset(W,0,sizeof(W));
        for (int i = 0; S[i]; i++) if (isalpha(S[i])) W[S[i]-'a']++;
        int ret = 0;
        for (int k = 0; k < N; k++) {
            bool ok = 1;
            for (int j = 0; ok && j < 26; j++) if (D[k][j] > W[j]) ok = 0;
            if (ok) ret++;
        }
        printf("%d\n", ret);
    }

    return 0;
}
