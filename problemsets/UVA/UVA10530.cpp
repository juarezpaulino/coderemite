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

    int N;
    char S[10];
    int low = 0, high = 11;
    while (scanf("%d", &N)) {
        if (!N) break;
        scanf("%*s %s", S);
        if (!strcmp(S, "low")) low = max(low, N);
        else if (!strcmp(S, "high")) high = min(high, N);
        else {
            if (N > low && N < high) puts("Stan may be honest");
            else puts("Stan is dishonest");
            low = 0; high = 11;
        }
    }

    return 0;
}
