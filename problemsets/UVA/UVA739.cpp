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
#include <set>
#include <queue>

using namespace std;

map<char, int> M;
char S[100];

int main() {

    M['B'] = 1;
    M['P'] = 1;
    M['F'] = 1;
    M['V'] = 1;
    M['C'] = 2;
    M['S'] = 2;
    M['K'] = 2;
    M['G'] = 2;
    M['J'] = 2;
    M['Q'] = 2;
    M['X'] = 2;
    M['Z'] = 2;
    M['D'] = 3;
    M['T'] = 3;
    M['L'] = 4;
    M['M'] = 5;
    M['N'] = 5;
    M['R'] = 6;

    printf("%9s%-25s%s", "", "NAME", "SOUNDEX CODE\n");
    while (gets(S)) {
        printf("%9s%-25s", "", S);
        putchar(*S);
        int k = 0;
        int l = M[*S];
        for (int i = 1; S[i] && k < 3; i++) {
            int v = M[S[i]];
            if (v && v != l) {
                k++;
                putchar('0'+v);
            }
            l = v;
        }
        while (k < 3) putchar('0'), k++;
        putchar('\n');
    }
    printf("%19sEND OF OUTPUT\n", "");

    return 0;
}
