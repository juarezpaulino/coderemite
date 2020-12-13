/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int MAX_SET = 1010;

int up[MAX_SET];

void init(int n) { for (int i = 0; i < n; i++) up[i] = -1; }

int root(int k) { return up[k] < 0 ? k : (up[k] = root(up[k])); }

bool join(int k, int m) {
    if ((k = root(k)) == (m = root(m))) return false;
    if (up[k] < up[m]) up[k] += up[m], up[m] = k;
    else up[m] += up[k], up[k] = m;
    return true;
}


typedef pair<int,int> pii;

int main() {

    int M, N;
    while (scanf("%d %d", &N, &M) && (M|N)) {
        priority_queue<pair<int,pii> > q;
        while (M--) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);
            q.push(make_pair(-c, pii(u,v)));
        }
        vector<int> W;
        init(N);
        while (!q.empty()) {
            int u = q.top().second.first,
                v = q.top().second.second,
                c = -q.top().first;
            q.pop();
            if (!join(u,v)) W.push_back(c);
        }
        M = W.size();
        if (!M) puts("forest");
        else for (int i = 0; i < M; i++) {
            if (i==M-1) printf("%d\n", W[i]);
            else printf("%d ", W[i]);
        }
    }

    return 0;
}
