/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <string>
#include <cctype>
#include <map>

using namespace std;

char D[256];

string standard(string s) {
    string ret;
    for (int i = 0; i < s.size(); i++) {
        if (s[i]=='-') continue;
        if (isdigit(s[i])) ret += s[i];
        else ret += D[s[i]];
    }
    return ret.substr(0,3) + "-" + ret.substr(3);
}

int main() {

    D['A'] = D['B'] = D['C'] = '2';
    D['D'] = D['E'] = D['F'] = '3';
    D['G'] = D['H'] = D['I'] = '4';
    D['J'] = D['K'] = D['L'] = '5';
    D['M'] = D['N'] = D['O'] = '6';
    D['P'] = D['R'] = D['S'] = '7';
    D['T'] = D['U'] = D['V'] = '8';
    D['W'] = D['X'] = D['Y'] = '9';
    int T;
    scanf("%d", &T);
    while (T--) {
        bool ok = 0;
        int N;
        char S[1010];
        map<string, int> M;

        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%s", S);
            string s = standard(S);
            M[s]++;
            if (M[s] >= 2) ok = 1;
        }

        if (!ok) puts("No duplicates.");
        else for (map<string, int>::iterator it = M.begin(); it != M.end(); it++) if (it->second >= 2)
            printf("%s %d\n", it->first.c_str(), it->second);
        if (T) putchar('\n');
    }

    return 0;
}
