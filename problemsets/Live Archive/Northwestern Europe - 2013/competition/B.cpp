/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <stack>
#include <set>

using namespace std;


int main() {

    int S[1000];
    int N, M;
    while (scanf("%d %d", &N, &M) != EOF) {
        set<int> in[1010];
        for (int i = 0; i < N; i++) scanf("%d", S+i);
        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--; v--;
            in[u].insert(v);
            in[v].insert(u);
        }
        int ret = 0;
        for (int i = 0; i < N; i++) {
            ret = max(ret, S[i]);
            for (int j = i+1; j < N; j++) if (in[i].count(j)) {
                ret = max(ret, S[i]+S[j]);
                for (int k = j+1; k < N; k++) if (in[i].count(k) && in[j].count(k)) {
                    ret = max(ret, S[i]+S[j]+S[k]);
                    for (int l = k+1; l < N; l++) if (in[i].count(l) && in[j].count(l) && in[k].count(l))
                        ret = max(ret, S[i]+S[j]+S[k]+S[l]);
                }
            }
        }
        printf("%d\n", ret);
    }

    return 0;
}
