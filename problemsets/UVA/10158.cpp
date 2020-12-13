/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX_SET = 20202;

int up[MAX_SET];

void init(int n) { for (int i = 0; i < n; i++) up[i] = -1; }

int root(int k) { return up[k] < 0 ? k : (up[k] = root(up[k])); }

bool join(int k, int m) {
    if ((k = root(k)) == (m = root(m))) return false;
    if (up[k] < up[m]) up[k] += up[m], up[m] = k;
    else up[m] += up[k], up[k] = m;
    return true;
}

int N;

inline int enemy(int u) { return u+N; }

int main() {

    scanf("%d", &N);
    init(2*N);
    int c, a, b;
    while (scanf("%d %d %d", &c, &a, &b) != EOF) {
        if (!(c|a|b)) break;
        if (c == 1) {
            if (root(a) == root(enemy(b))) { printf("-1\n"); continue; }
            join(a, b);
            join(enemy(a), enemy(b));
        }
        else if (c == 2) {
            if (root(a) == root(b)) { printf("-1\n"); continue; }
            join(a, enemy(b));
            join(enemy(a), b);
        }
        else if (c == 3) printf("%d\n", root(a) == root(b));
        else if (c == 4) printf("%d\n", root(a) == root(enemy(b)));
    }

    return 0;
}
