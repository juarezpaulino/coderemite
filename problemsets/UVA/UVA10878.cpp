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

int main() {

    gets(S);
    while (gets(S)) {
        if (!strcmp(S,"___________")) break;
        int ret = 0;
        for (int i = 1; S[i] != '|'; i++) if (S[i] != '.') ret = ret*2 + (S[i]=='o');
        putchar(ret);
    }

    return 0;
}
