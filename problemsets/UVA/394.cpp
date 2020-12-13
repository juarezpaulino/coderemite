/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct array {
    int B, s, D;
    vector<int> l, u, C;
};

map<string, int> M;

vector<array> V;

int main() {

    int N, R;
    char S[1010];
    scanf("%d %d", &N, &R);
    for (int i = 0; i < N; i++) {
        int id = V.size();
        array a;
        scanf("%s %d %d %d", S, &a.B, &a.s, &a.D);
        a.l.resize(a.D+1); a.u.resize(a.D+1);
        for (int j = 1; j <= a.D; j++) scanf("%d %d", &a.l[j], &a.u[j]);
        M[S] = id;
        V.push_back(a);
        V[id].C.resize(a.D+1);
        V[id].C[a.D] = V[id].s;
        for (int k = a.D-1; k > 0; k--) V[id].C[k] = V[id].C[k+1] * (V[id].u[k+1] - V[id].l[k+1] + 1);
        V[id].C[0] = V[id].B;
        for (int k = 1; k <= V[id].D; k++) V[id].C[0]-=V[id].C[k]*V[id].l[k];
    }
    for (int i = 0; i < R; i++) {
        scanf("%s", S);
        int id = M[S];
        vector<int> ind;
        int x;
        for (int j = 0; j < V[id].D; j++) scanf("%d", &x), ind.push_back(x);
        int ret = V[id].C[0];
        for (int j = 1; j <= V[id].D; j++) ret += V[id].C[j]*ind[j-1];
        printf("%s[%d", S, ind[0]);
        for (int j = 1; j < V[id].D; j++) printf(", %d", ind[j]);
        printf("] = %d\n", ret);
    }

    return 0;
}





