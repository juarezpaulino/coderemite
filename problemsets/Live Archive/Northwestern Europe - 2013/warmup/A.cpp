/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;


int main() {


    char S[1010];
    while (gets(S)) {
        int l = 0, r = 0;
        for (int i = 0; S[i]; i++) if (S[i]=='L') l++; else r++;
        if (l == r) puts("ok");
        else puts("missing");
    }

    return 0;
}
