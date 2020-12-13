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
#include <numeric>

using namespace std;

int T;
char S[100100];

int main() {

    scanf("%d ", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case %d:", t);
        int p = 0;
        unsigned char M[110] = {0};
        gets(S);
        for (int i = 0; S[i]; i++) {
            if (S[i]=='.') continue;
            else if (S[i]=='<') p = (p + 99) % 100;
            else if (S[i]=='>') p = (p + 1) % 100;
            else if (S[i]=='+') M[p] = (M[p] + 1) % 256;
            else if (S[i]=='-') M[p] = (M[p] + 255) % 256;
        }
        for (int i = 0; i < 100; i++) printf(" %02X", M[i]);
        putchar('\n');
    }

    return 0;
}
