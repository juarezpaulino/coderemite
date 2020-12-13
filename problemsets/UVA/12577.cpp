/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>

using namespace std;

int main() {

    char S[100];
    int id = 1;
    while (gets(S)) {
        if (S == string("*")) break;
        printf("Case %d: ", id++);
        if (S == string("Hajj")) puts("Hajj-e-Akbar");
        else puts("Hajj-e-Asghar");
    }

    return 0;
}
