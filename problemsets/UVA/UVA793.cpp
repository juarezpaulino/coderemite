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

const int MAX_SET = 100100;
int up[MAX_SET];
void init(int n) { for (int i = 0; i < n; i++) up[i] = -1; }
int root(int k) { return up[k] < 0 ? k : (up[k] = root(up[k])); }
bool join(int k, int m) {
    if ((k = root(k)) == (m = root(m))) return false;
    if (up[k] < up[m]) up[k] += up[m], up[m] = k;
    else up[m] += up[k], up[k] = m;
    return true;
}


int main() {

    int T, N, N1, N2;
    scanf("%d", &T);
    while (T--) {
        scanf("%d ", &N);
        init(N+10);
        N1 = N2 = 0;
        char S[1000];
        while (gets(S)) {
            if (*S==0) break;
            char t;
            int u, v;
            istringstream is(S);
            is >> t >> u >> v;
            if (t == 'c') join(u,v);
            else if (root(u)==root(v)) N1++;
            else N2++;
        }
        printf("%d,%d\n", N1, N2);
        if (T) putchar('\n');
    }

    return 0;
}
