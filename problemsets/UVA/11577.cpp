/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {

    int T;
    char S[1010];
    scanf("%d ", &T);
    while (T--) {
        gets(S);
        int C[256] = {0};
        int ret = 0;
        for (int i = 0; S[i]; i++) if (isalpha(S[i])) ret = max(ret, ++C[tolower(S[i])]);
        for (int i = 'a'; i <= 'z'; i++) if (C[i]==ret) putchar(i);
        putchar('\n');
    }


    return 0;
}
