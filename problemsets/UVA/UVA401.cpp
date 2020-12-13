/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>

using namespace std;

map<char, char> R;

int main() {

    R['A'] = 'A'; R['E'] = '3'; R['H'] = 'H'; R['I'] = 'I'; R['J'] = 'L';
    R['L'] = 'J'; R['M'] = 'M'; R['O'] = 'O'; R['S'] = '2'; R['T'] = 'T';
    R['U'] = 'U'; R['V'] = 'V'; R['W'] = 'W'; R['X'] = 'X'; R['Y'] = 'Y';
    R['Z'] = '5'; R['1'] = '1'; R['2'] = 'S'; R['3'] = 'E'; R['5'] = 'Z';
    R['8'] = '8';

    char S[1000];
    while (gets(S)) {
        bool P = true, M = true;
        int N = strlen(S);
        for (int i = 0; i < N/2; i++) {
            if (S[i] != S[N-1-i]) P = false;
            if (S[i] != R[S[N-1-i]]) M = false;
        }
        if (N%2 && S[N/2] != R[S[N/2]]) M = false;
        if (!P && !M) printf("%s -- is not a palindrome.\n\n", S);
        else if (!P && M) printf("%s -- is a mirrored string.\n\n", S);
        else if (P && !M) printf("%s -- is a regular palindrome.\n\n", S);
        else printf("%s -- is a mirrored palindrome.\n\n", S);
    }


    return 0;
}
