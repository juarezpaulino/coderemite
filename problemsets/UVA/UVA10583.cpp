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

const int MAX_SET = 50001;
int up[MAX_SET];
void init(int n) { for (int i = 0; i < n; i++) up[i] = -1; }
int root(int k) { return up[k] < 0 ? k : (up[k] = root(up[k])); }
bool join(int k, int m) {
    if ((k = root(k)) == (m = root(m))) return false;
    if (up[k] < up[m]) up[k] += up[m], up[m] = k;
    else up[m] += up[k], up[k] = m;
    return true;
}

int N, M;

int main() {

    int T = 1;
    while (scanf("%d %d", &N, &M)) {
        if (!(N|M)) break;
        init(N+1);
        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            join(u,v);
        }
        int ret = 0;
        for (int i = 1; i <= N; i++) if (up[i] < 0) ret++;
        printf("Case %d: %d\n", T++, ret);
    }

    return 0;
}
