/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> M;
vector<vector<int> > sol;
char row[20], ld[20], rd[20];

void solve(int c) {
    if (c == 8) {
        sol.push_back(M);
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (row[i] || ld[i-c+7] || rd[i+c]) continue;
        row[i] = ld[i-c+7] = rd[i+c] = 1;
        M[c] = i;
        solve(c+1);
        row[i] = ld[i-c+7] = rd[i+c] = 0;
    }
}


int main() {

    int t = 1;
    M = vector<int>(8, -1);
    solve(0);
    while (1) {
        for (int i = 0; i < 8; i++) {
            int u;
            if (scanf("%d", &u) == EOF) return 0;
            M[i] = u-1;
        }
        int ret = 8;
        for (int i = 0; i < sol.size(); i++) {
            int u = 0;
            for (int j = 0; j < 8; j++) if (sol[i][j] != M[j]) u++;
            ret = min(ret, u);
        }
        printf("Case %d: %d\n", t++, ret);
    }


    return 0;
}
