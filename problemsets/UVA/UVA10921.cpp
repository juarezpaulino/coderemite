/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <queue>

using namespace std;

map<char, int> M;
char S[100], T[100];

int main() {

    M['A'] = M['B'] = M['C'] = '2';
    M['D'] = M['E'] = M['F'] = '3';
    M['G'] = M['H'] = M['I'] = '4';
    M['J'] = M['K'] = M['L'] = '5';
    M['M'] = M['N'] = M['O'] = '6';
    M['P'] = M['Q'] = M['R'] = M['S'] = '7';
    M['T'] = M['U'] = M['V'] = '8';
    M['W'] = M['X'] = M['Y'] = M['Z'] = '9';

    while (gets(S)) {
        int N = strlen(S);
        for (int i = 0; i < N; i++)
            if (!M.count(S[i])) T[i] = S[i];
            else T[i] = M[S[i]];
        T[N] = 0;
        puts(T);
    }

    return 0;
}
