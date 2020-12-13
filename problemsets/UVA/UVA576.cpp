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

char S[1000];

bool isvowel(char c) {
    c = toupper(c);
    return (c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='Y');
}

int main() {

    while (gets(S)) {
        if (!strcmp(S,"e/o/i")) break;
        int N = strlen(S);
        S[N++] = '/'; S[N] = 0;
        int k = 1;
        int i = 0;
        int s = 0;
        while (S[i]) {
            while (S[i] && S[i]!='/' && !isvowel(S[i])) i++;
            if (isvowel(S[i])) s++;
            while (S[i] && isvowel(S[i])) i++;
            if (S[i]=='/') {
                if (((k==1||k==3)&&s!=5) || (k==2&&s!=7)) break;
                s = 0;
                k++;
                i++;
            }
        }
        if (S[i]) printf("%d\n", k);
        else puts("Y");
    }

    return 0;
}
