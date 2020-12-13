/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        vector<int> F[2];
        int N;
        scanf("%d", &N);
        while (N--) {
            int x;
            scanf("%d", &x);
            if (x > 0) F[0].push_back(x);
            else F[1].push_back(-x);
        }
        sort(F[0].begin(), F[0].end());
        sort(F[1].begin(), F[1].end());
        if (!F[0].size() && !F[1].size()) { puts("0"); continue; }
        if (!F[0].size() || !F[1].size()) { puts("1"); continue; }
        int k = 1, p[2] = {0};
        if (F[0][0] < F[1][0]) k = 0;
        int l = -1, ret = 0;
        while (1) {
            while (p[k] < F[k].size() && F[k][p[k]] < l) p[k]++;
            if (p[k] == F[k].size()) break;
            ret++;
            l = F[k][p[k]];
            k ^= 1;
        }
        printf("%d\n", ret);
    }

    return 0;
}
