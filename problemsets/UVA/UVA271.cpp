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

char S[300];
int p;

bool expr() {
    if (S[p]>='p' && S[p]<='z') { p++; return true; }
    if (S[p]=='N') {
        p++;
        return expr();
    }
    else if (S[p]) {
        p++;
        return expr() && expr();
    }
    return false;
}

int main() {

    while (gets(S)) {
        p = 0;
        if (expr() && !S[p]) puts("YES");
        else puts("NO");
    }

    return 0;
}
