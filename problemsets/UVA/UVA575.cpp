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

int main() {

    char S[1000];
    while (gets(S)) {
        int N = strlen(S);
        if (N == 1 && *S == '0') break;
        int ret = 0;
        for (int i = N-1; i >= 0; i--) ret += (S[i]-'0') * ((1<<(N-i)) - 1);
        printf("%d\n", ret);
    }

    return 0;
}
