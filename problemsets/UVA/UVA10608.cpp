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

const int MAX_SET = 35000;
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

    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &M);
        init(N);
        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--; v--;
            join(u,v);
        }
        int ret = 0;
        for (int i = 0; i < N; i++) if (up[i]<0) ret = max(ret, abs(up[i]));
        printf("%d\n", ret);
    }

    return 0;
}
