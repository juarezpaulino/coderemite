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

char S[100];
char D[50], U[50];

int main() {

    gets(D);
    gets(U);
    while (gets(S)) {
        int c;
        bool d = true;
        for (int i = 0; S[i]; i+=5) {
            c = ((S[i]-'0')*16)+((S[i+1]-'0')*8)+((S[i+2]-'0')*4)+((S[i+3]-'0')*2)+(S[i+4]-'0');
            if (c == 31) d = false;
            else if (c == 27) d = true;
            else if (d) putchar(D[c]);
            else putchar(U[c]);
        }
        putchar('\n');
    }

    return 0;
}
