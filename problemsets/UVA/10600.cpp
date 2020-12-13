/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

const int MAX_SET = 1010;

int up[MAX_SET];

void init(int n) { for (int i = 1; i <= n; i++) up[i] = -1; }

int root(int k) { return up[k] < 0 ? k : (up[k] = root(up[k])); }

bool join(int k, int m) {
    if ((k = root(k)) == (m = root(m))) return false;
    if (up[k] < up[m]) up[k] += up[m], up[m] = k;
    else up[m] += up[k], up[k] = m;
    return true;
}

struct edge { int u, v, w; };

edge E[10101];

bool cmp(const edge &e1, const edge &e2) {
    return e1.w < e2.w;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        set<int> TREE;
        scanf("%d %d", &N, &M);
        for (int i = 0; i < M; i++)
            scanf("%d %d %d", &E[i].u, &E[i].v, &E[i].w);
        sort(E, E+M, cmp);
        init(N);
        int ret1 = 0, ret2 = -1;
        vector<int> C;
        for (int i = 0; i < M; i++) if (join(E[i].u, E[i].v)) {
            ret1+=E[i].w;
            TREE.insert(i);
            C.push_back(i);
        }
        for (int k = 0; k < C.size(); k++) {
            init(N);
            edge &ek = E[C[k]];
            for (int i = 0; i < C.size(); i++) if (i!=k) join(E[C[i]].u, E[C[i]].v);
            for (int i = 0; i < M; i++) if (!TREE.count(i)) {
                if (join(E[i].u, E[i].v)) {
                    if (ret2 == -1 || ret2 > ret1-ek.w+E[i].w)
                        ret2 = ret1-ek.w+E[i].w;
                    break;
                }
            }
        }
        printf("%d %d\n", ret1, ret2);
    }

    return 0;
}
