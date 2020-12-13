/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

typedef pair<int,int> pii;

int N, M, A;

const int MAX_SET = 10101;

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

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d %d %d", &N, &M, &A);
        priority_queue<pair<int,pii> > q;
        while (M--) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            q.push(make_pair(-c, pii(u,v)));
        }
        init(N+1);
        int ret = 0, na = 0;
        while (!q.empty()) {
            int u = q.top().second.first,
                v = q.top().second.second,
                c = -q.top().first;
            q.pop();

            u = root(u); v = root(v);
            if (u != v) {
                if (c >= A) break;
                else ret += c;
                join(u,v);
            }
        }
        for (int i = 1; i <= N; i++) if (root(i)==i) ret += A, na++;
        printf("Case #%d: %d %d\n", t, ret, na);
    }

    return 0;
}
