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
#include <numeric>

using namespace std;

int T;
char S[50];
map<char,int> R;

int main() {

    R['A'] = 0; R['C'] = 1; R['G'] = 2; R['T'] = 3;
    scanf("%d ", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%s", S);
        long long ret = 0;
        for (int i = 0; S[i]; i++) ret = (ret*4) + R[S[i]];
        printf("Case %d: (%d:%lld)\n", t, strlen(S), ret);
    }

    return 0;
}
