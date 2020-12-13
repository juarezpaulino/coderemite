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

map<string, int> MAPA;

int main() {

    MAPA["zero"] = 0; MAPA["one"] = 1; MAPA["two"] = 2; MAPA["three"] = 3; MAPA["four"] = 4;
    MAPA["five"] = 5; MAPA["six"] = 6; MAPA["seven"] = 7; MAPA["eight"] = 8; MAPA["nine"] = 9;
    MAPA["ten"] = 10; MAPA["eleven"] = 11; MAPA["twelve"] = 12; MAPA["thirteen"] = 13; MAPA["fourteen"] = 14;
    MAPA["fifteen"] = 15; MAPA["sixteen"] = 16; MAPA["seventeen"] = 17; MAPA["eighteen"] = 18; MAPA["nineteen"] = 19;
    MAPA["twenty"] = 20; MAPA["thirty"] = 30; MAPA["forty"] = 40; MAPA["fifty"] = 50; MAPA["sixty"] = 60;
    MAPA["seventy"] = 70; MAPA["eighty"] = 80; MAPA["ninety"] = 90; MAPA["hundred"] = 100; MAPA["thousand"] = 1000;
    MAPA["million"] = 1000000;

    char S[1000];
    while (gets(S)) {
        int ret = 0, s = 1, k = 0;
        istringstream is(S);
        while (is >> S) {
            if (!strcmp(S,"negative")) s = -1;
            else if (!strcmp(S,"hundred")) k = k*MAPA[S];
            else if (!strcmp(S,"thousand") || !strcmp(S,"million")) ret = ret + k * MAPA[S], k = 0;
            else k += MAPA[S];
        }
        ret += k;
        if (s==-1) ret = -ret;
        printf("%d\n", ret);
    }

    return 0;
}
