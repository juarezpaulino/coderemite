/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

int S[20];
int N;
vector<vector<int> > R;

int main() {

    bool f = false;
    while (scanf("%d", &N)) {
        if (!N) break;
        if (f) putchar('\n');
        f = true;
        R.clear();
        for (int i = 0; i < N; i++) scanf("%d", S+i);
        sort(S, S+N);
        int k = 6;
        int s = (1 << k) - 1;
        while (!(s & 1 << N)) {

            vector<int> r;
            for (int i = 0; i < N; i++) if (s & (1<<i))
                r.push_back(S[i]);
            R.push_back(r);

            int lo = s & ~(s-1); int lz = (s + lo) & ~s;
            s |= lz; s &= ~(lz-1); s |= (lz / lo / 2)-1;
        }
        sort(R.begin(), R.end());
        for (int i = 0; i < R.size(); i++) {
            printf("%d", R[i][0]);
            for (int j = 1; j < 6; j++) printf(" %d", R[i][j]);
            putchar('\n');
        }
    }

    return 0;
}
