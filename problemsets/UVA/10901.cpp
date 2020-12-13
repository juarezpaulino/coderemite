/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

struct ferry {
    int t, p;
    bool operator<(const ferry &B) const {
        if (t != B.t) return t > B.t;
        return p > B.p;
    }
};

int ret[10101];

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, t, m;
        priority_queue<ferry> Q[2];
        scanf("%d %d %d", &n, &t, &m);
        for (int i = 0; i < m; i++) {
            int t; char side[10];
            scanf("%d %s", &t, side);
            if (side == string("left")) Q[0].push((ferry){t,i});
            else Q[1].push((ferry){t,i});
        }
        int s = 0, cur = -10000;
        while (!Q[0].empty() || !Q[1].empty()) {
            if (Q[s].empty()) {
                cur = max(cur, Q[1-s].top().t) + t;
                s = 1-s;
            }
            else if (cur >= Q[s].top().t) {
                int k = 0;
                while (!Q[s].empty() && k < n && cur >= Q[s].top().t) {
                    ret[Q[s].top().p] = cur + t;
                    Q[s].pop();
                    k++;
                }
                cur += t;
                s = 1-s;
            }
            else {
                if (Q[1-s].empty()) cur = Q[s].top().t;
                else if (Q[1-s].top().t < Q[s].top().t) {
                    cur = max(cur, Q[1-s].top().t) + t;
                    s = 1-s;
                }
                else cur = Q[s].top().t;
            }
        }
        for (int i = 0; i < m; i++) printf("%d\n", ret[i]);
        if (T) putchar('\n');
    }

    return 0;
}
