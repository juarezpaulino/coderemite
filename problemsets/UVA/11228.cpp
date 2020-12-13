/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

typedef pair<int,int> pii;

int X[1010], Y[1010];
int N, R;

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
        scanf("%d %d", &N, &R);
        R *= R;
        priority_queue<pair<int, pii> > q;
        for (int i = 0; i < N; i++) {
            scanf("%d %d", X+i, Y+i);
            for (int j = 0; j < i; j++) {
                int dy = Y[i]-Y[j];
                int dx = X[i]-X[j];
                int d = dy*dy+dx*dx;
                q.push(make_pair(-d, make_pair(i,j)));
            }
        }
        int c = 1;
        double r1 = 0., r2 = 0.;
        init(N);
        while (!q.empty()) {
            int u = q.top().second.first, v = q.top().second.second, d2 = -q.top().first;
            q.pop();
            if (join(u,v)) {
                double d = sqrt(d2);
                if (d2 > R) c++, r2 += d;
                else r1 += d;
            }
        }
        printf("Case #%d: %d %.0lf %.0lf\n", t, c, r1+1E-10, r2+1E-10);
    }

    return 0;
}
