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

map<string, string> DIC;

char S[100];

int main() {

    while (gets(S)) {
        if (!*S) break;
        char A[100], B[100];
        sscanf(S, "%s %s", A, B);
        DIC[B] = A;
    }
    while (gets(S)) {
        if (!DIC.count(S)) puts("eh");
        else printf("%s\n", DIC[S].c_str());
    }

    return 0;
}
