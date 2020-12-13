/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

char S[1010101], T[1010101];

int main() {

    while (gets(S)) {
        if (string(S) == "END") break;
        for (int i = 1; ; i++) {
            int s = string(S).size();
            sprintf(T, "%d", s);
            if (string(S) == string(T)) {
                printf("%d\n", i);
                break;
            }
            strcpy(S, T);
        }
    }

    return 0;
}
