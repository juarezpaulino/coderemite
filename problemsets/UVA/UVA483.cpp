/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <sstream>
#include <algorithm>

using namespace std;

char S[100000];

int main() {

    while (gets(S)) {
        int i = 0;
        while (S[i]) {
            while (S[i]==' ') putchar(' '), i++;
            char W[1000];
            int k = 0;
            while (S[i]!=' ' && S[i]) {
                W[k++] = S[i++];
            }
            W[k] = 0;
            reverse(W, W+k);
            printf("%s", W);
        }
        putchar('\n');
    }

    return 0;
}
