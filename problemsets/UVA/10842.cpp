/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

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


int main() {

    int N, M;
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%d %d", &N, &M);
        priority_queue<pair<int,pii> > q;
        while (M--) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            q.push(make_pair(c, pii(u,v)));
        }
        int ret;
        init(N);
        while (!q.empty()) {
            int u = q.top().second.first,
                v = q.top().second.second,
                c = q.top().first;
            q.pop();
            if (join(u,v)) ret = c;
        }
        printf("%d\n", ret);
    }

    return 0;
}
