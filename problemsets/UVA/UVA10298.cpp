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


int main() {

    char S[1010101];
    while (gets(S)) {
        if (*S=='.') break;
        string s = S;
        int N = s.size();
        int k;
        for (k = 1; k <= N; k++) {
            if (N%k != 0) continue;
            string p = s.substr(0,k);
            bool ok = true;
            for (int i = k; i < N; i+=k) if (s.substr(i,k) != p) { ok = false; break; }
            if (ok) break;
        }
        printf("%d\n", N/k);
    }

    return 0;
}
