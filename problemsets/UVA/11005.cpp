/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

char B[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int W[36];

int main() {

    int T; scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        printf("Case %d:\n", t);

        for (int i = 0; i < 36; i++) scanf("%d", W+i);
        int Q; scanf("%d", &Q);
        while (Q--) {
            int x; scanf("%d", &x); printf("Cheapest base(s) for number %d:", x);
            int v = 0x3F3F3F3F;
            vector<int> ret;
            for (int b = 2; b <= 36; b++) {
                int u = 0, m = x;
                while (m) { u += W[m%b]; m/=b; }
                if (u < v) ret.clear(), ret.push_back(b), v = u;
                else if (u == v) ret.push_back(b);
            }
            for (int i = 0; i < ret.size(); i++) printf(" %d", ret[i]);
            putchar('\n');
        }

        if (t < T) putchar('\n');
    }

    return 0;
}
