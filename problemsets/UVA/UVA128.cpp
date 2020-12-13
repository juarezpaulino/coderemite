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

char S[1050];

int main() {

    while (gets(S)) {
        if (*S=='#') break;
        long long sum = 0;
        for (int i = 0; S[i]; i++)
            sum = (((sum << 8) % 34943) + S[i]) % 34943;
        sum = (sum << 16) % 34943;
        int ret = (34943 - sum) % 34943;
        printf("%02X %02X\n", ret>>8, ret%256);
    }

    return 0;
}
