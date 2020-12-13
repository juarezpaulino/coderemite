/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<double,double> pdd;

pdd V[10101];

#define EPS 1E-10

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

bool comp(const pdd &A, const pdd &B) {
    if (cmp(A.first,B.first) != 0) return A.first < B.first;
    return A.second > B.second;
}

int main() {

    int N, L, W;
    while (scanf("%d %d %d", &N, &L, &W) != EOF) {
        int p, r;
        double w2 = W/2.;
        int k = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d %d", &p , &r);
            if (cmp(r,w2) <= 0) continue;
            double y = sqrt((double)r*r - w2*w2);
            V[k].first = max(0.,p-y);
            V[k].second = min((double)L,p+y);
            k++;
        }
        sort(V, V+k, comp);
        double last = 0.;
        int ret = 0;
        bool ok = 0;
        for (int i = 0; i < k; ) {
            int p = -1;
            while (i < k && cmp(V[i].first,last) <= 0) {
                if (p==-1 || V[i].second > V[p].second)
                    p = i;
                i++;
            }
            if (p == -1) break;
            last = V[p].second;
            ret++;
            if (cmp(last,L) >= 0) { ok = 1; break; }
        }
        if (!ok) puts("-1");
        else printf("%d\n", ret);
    }

    return 0;
}
