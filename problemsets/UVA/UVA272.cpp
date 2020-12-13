/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    bool p = false;
    char S[1000], T[1000];

    while (gets(S)) {
        int j = 0;
        for (int i = 0; S[i]; i++)
            if (S[i]=='"') {
                if (p) T[j++] = '\'', T[j++] = '\'';
                else T[j++] = '`', T[j++] = '`';
                p ^= 1;
            }
            else T[j++] = S[i];
        T[j] = 0;
        puts(T);
    }

    return 0;
}
