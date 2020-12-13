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

int main() {

    char S[100];
    int X;
    while (gets(S)) {
        if (*S=='-') break;
        if (S[0]=='0' && S[1]=='x') {
            sscanf(S, "%x", &X);
            printf("%d\n", X);
        }
        else {
            sscanf(S, "%d", &X);
            printf("0x%X\n", X);
        }
    }


    return 0;
}
