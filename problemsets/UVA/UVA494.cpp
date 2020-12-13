/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cctype>

using namespace std;

int main() {

    char S[1000];
    bool f = false;

    while (gets(S)) {
        int ret = 0;
        for (int i = 0; S[i]; i++) {
            if (!f && isalpha(S[i])) ret++, f = true;
            else if (f && !isalpha(S[i])) f = false;
        }
        printf("%d\n", ret);
    }

    return 0;
}
