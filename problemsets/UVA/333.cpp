/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cctype>

using namespace std;

char V[] = "-0123456789X";

inline bool legal(char c) {
    for (int i = 0; V[i]; i++) if (c == V[i]) return true;
    return false;
}

int main() {

    char L[1010], S[1010];
    while (gets(L)) {
        int k = 0, i;
        for (i = 0; L[i] && isspace(L[i]); i++);
        while (L[i]) S[k++] = L[i++];
        while (k-1 >= 0 && isspace(S[k-1])) k--;
        S[k] = 0;
        bool ok = 1;
        for (int i = 0; ok && S[i]; i++) if (!legal(S[i])) ok = 0;
        int ret = 0, s = 0, c = 0;
        for (int i = 0; ok && S[i]; i++) {
            if (S[i]=='X') {
                if (c != 9) ok = 0;
                s += 10, ret += s, c++;
            }
            else if (isdigit(S[i])) s += S[i]-'0', ret += s, c++;
        }
        if (ok && c == 10 && ret%11==0) printf("%s is correct.\n", S);
        else printf("%s is incorrect.\n", S);
    }

    return 0;
}
