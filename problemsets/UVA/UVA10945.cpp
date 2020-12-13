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

int main() {

    while (gets(S)) {
        if (!strcmp(S, "DONE")) break;
        int i = 0, j = strlen(S)-1;
        while (i < j) {
            if (!isalpha(S[i])) { i++; continue; }
            if (!isalpha(S[j])) { j--; continue; }
            if (tolower(S[i]) != tolower(S[j])) break;
            i++; j--;
        }
        if (i < j) puts("Uh oh..");
        else puts("You won't be eaten!");
    }

    return 0;
}
