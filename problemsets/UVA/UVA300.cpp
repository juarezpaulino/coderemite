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

int d;
int hd, hm, hy;
int td, tmt, ty;
char S[100];
char HM[19][30] = {
    "pop", "no", "zip", "zotz", "tzec", "xul",
    "yoxkin", "mol", "chen", "yax", "zac", "ceh",
    "mac", "kankin", "muan", "pax", "koyab", "cumhu",
    "uayet"
};
char TM[20][30] = {
    "imix", "ik", "akbal", "kan", "chicchan", "cimi",
    "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben",
    "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
};
map<string, int> MAPA;

int main() {

    int N;
    scanf("%d", &N);
    printf("%d\n", N);
    while (N--) {
        scanf("%d. %s %d", &hd, S, &hy);
        for (hm = 0; strcmp(HM[hm], S); hm++);
        d = hy*365 + hm*20 + hd + 1;
        ty = (d-1) / 260; d -= ty*260;
        tmt = (d-1)%20;
        td = ((d-1)%13) + 1;
        printf("%d %s %d\n", td, TM[tmt], ty);
    }

    return 0;
}
