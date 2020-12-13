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
#include <map>

using namespace std;

map<char, int> M;

int main() {

    M['B'] = M['F'] = M['P'] = M['V'] = 1;
    M['C'] = M['G'] = M['J'] = M['K'] = M['Q'] = M['S'] = M['X'] = M['Z'] = 2;
    M['D'] = M['T'] = 3;
    M['L'] = 4;
    M['M'] = M['N'] = 5;
    M['R'] = 6;

    char S[100];
    while (gets(S)) {
        int k = -1;
        for (int i = 0; S[i]; i++) {
            if (!M.count(S[i])) { k = -1; continue; }
            int v = M[S[i]];
            if (v != k) putchar('0'+v);
            k = v;
        }
        putchar('\n');
    }

    return 0;
}
