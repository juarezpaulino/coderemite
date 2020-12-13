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

int M, N;
char S[100];

int main() {

    scanf("%d", &N);
    while (N--) {
        scanf("%s", S);
        M = strlen(S);
        int k;
        string s(S);
        for (k = 1; k <= M; k++) {
            if (M%k != 0) continue;
            string p = s.substr(0,k);
            bool ok = true;
            for (int j = k; S[j]; j += k)
                if (s.substr(j,k) != p) { ok = false; break; }
            if (ok) break;
        }
        printf("%d\n", k);
        if (N) putchar('\n');
    }

    return 0;
}
