/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {

    char S[1000];

    while (gets(S)) {
        for (int i = 0; S[i]; i++) S[i]-=7;
        puts(S);
    }

    return 0;
}
