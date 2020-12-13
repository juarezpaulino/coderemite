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

const int MAX_SET = 100001;
int up[MAX_SET];
void init(int n) { for (int i = 0; i < n; i++) up[i] = -1; }
int root(int k) { return up[k] < 0 ? k : (up[k] = root(up[k])); }
bool join(int k, int m) {
    if ((k = root(k)) == (m = root(m))) return false;
    if (up[k] < up[m]) up[k] += up[m], up[m] = k;
    else up[m] += up[k], up[k] = m;
    return true;
}

struct triple {
    int d, x, y;
    bool operator<(const triple &B) const {
        return d > B.d;
    }
};

int X[1000], Y[1000];

int main() {

    int N, M;
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) scanf("%d %d", X+i, Y+i);
        init(N);
        scanf("%d", &M);
        while (M--) {
            int x, y;
            scanf("%d %d", &x, &y);
            x--; y--;
            join(x,y);
        }
        priority_queue<triple> q;
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (root(i) != root(j)) {
            int dx = X[i]-X[j],
                dy = Y[i]-Y[j];
            q.push((triple){dx*dx+dy*dy, i, j});
        }
        double ret = 0;
        while (!q.empty()) {
            int x = q.top().x, y = q.top().y, d = q.top().d;
            q.pop();
            if (root(x) != root(y)) ret += sqrt(d), join(x,y);
        }
        printf("%.2lf\n", ret);
    }

    return 0;
}
