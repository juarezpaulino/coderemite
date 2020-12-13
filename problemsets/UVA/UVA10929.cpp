/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char S[1010];

int main() {

    while (gets(S)) {
        if (!S[1] && *S=='0') break;
        int ret = 0;
        for (int i = 0; S[i]; i++) ret = ret + ((i%2)?-(S[i]-'0'):S[i]-'0');
        if (ret%11==0) printf("%s is a multiple of 11.\n", S);
        else printf("%s is not a multiple of 11.\n", S);
    }

    return 0;
}
