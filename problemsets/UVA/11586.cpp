/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <sstream>
#include <string>

using namespace std;

char S[1010101];

int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        gets(S);
        istringstream is(S);
        string s;
        int oo = 0, ii = 0, n = 0;
        while (is >> s) {
            if (s == "FF") oo++;
            else if (s == "MM") ii++;
            n++;
        }
        if (ii != oo || n == 1) puts("NO LOOP");
        else puts("LOOP");
    }

    return 0;
}
