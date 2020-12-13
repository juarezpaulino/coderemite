/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

char S[1500];

int main() {

    while (1) {
        gets(S);
        if (*S == '*') break;
        istringstream is(S);
        is >> S;
        char F, F2;
        F = S[0];
        if (F >= 'a' && F <= 'z') F = F - 'a' + 'A';
        bool ok = true;
        while (is >> S) {
            F2 = S[0];
            if (F2 >= 'a' && F2 <= 'z') F2 = F2 - 'a' + 'A';
            if (F != F2) { ok = false; break; }
        }
        if (ok) puts("Y");
        else puts("N");
    }

    return 0;
}
