/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

int main() {

    char S[1000];
    while (gets(S)) {
        if (*S == 0) { putchar('\n'); continue; }
        int k = 0;
        for (int i = 0; S[i]; i++) {
            if (S[i] >= 'A' && S[i] <= 'Z') { for (int j = 0; j < k; j++) printf("%c", S[i]); k = 0; }
            else if (S[i]=='b') { for (int j = 0; j < k; j++) printf(" "); k = 0; }
            else if (S[i]=='*') { for (int j = 0; j < k; j++) printf("*"); k = 0; }
            else if (S[i]=='!') { putchar('\n'); k = 0; }
            else k += S[i]-'0';
        }
        putchar('\n');
    }

    return 0;
}
