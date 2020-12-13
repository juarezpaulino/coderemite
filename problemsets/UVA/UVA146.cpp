/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {

    char S[100];
    while (gets(S)) {
        if (*S=='#') break;
        if (!next_permutation(S, S+strlen(S))) puts("No Successor");
        else puts(S);
    }

    return 0;
}
