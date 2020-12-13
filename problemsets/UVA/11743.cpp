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
    char S[30];
    scanf("%d", &T);
    while (T--) {
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            scanf("%s", S);
            for (int j = 0; j < 4; j++) {
                if (j % 2) ret += S[j]-'0';
                else ret += (S[j] >= '5') ? 1+2*(S[j]-'0'-5) : 2*(S[j]-'0');
            }
        }
        if (ret % 10 == 0) puts("Valid");
        else puts("Invalid");
    }

    return 0;
}
