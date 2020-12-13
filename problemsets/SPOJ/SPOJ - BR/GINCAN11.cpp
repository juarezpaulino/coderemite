/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

const int MAX_SET = 1001;
int up[MAX_SET];
void init(int n) { for (int i = 1; i <= n; i++) up[i] = -1; }
int root(int k) { return up[k] < 0 ? k : (up[k] = root(up[k])); }
bool join(int k, int m) {
    if ((k = root(k)) == (m = root(m))) return false;
    if (up[k] < up[m]) up[k] += up[m], up[m] = k;
    else up[m] += up[k], up[k] = m;
    return true;
}


int main() {

    int N, M;

    scanf("%d %d", &N, &M);
    init(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        join(x,y);
    }
    int ret = 0;
    for (int i = 1; i <= N; i++) if (up[i]<=-1) ret++;
    printf("%d\n", ret);

    return 0;
}
