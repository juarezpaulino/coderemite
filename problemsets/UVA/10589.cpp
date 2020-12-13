/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int N, a;
    while (scanf("%d %d", &N, &a)) {
        if (!(N|a)) break;
        long long ret = 0;
        long long x, y, dx, dy, A = a*10000000LL, r2 = A*A;
        for (int i = 0; i < N; i++) {
            int b1, b2, c1, c2;
            scanf("%d.%d %d.%d", &b1, &c1, &b2, &c2);
            x = b1*10000000LL + c1;
            y = b2*10000000LL + c2;
            dx = x; dy = y;
            if (dx*dx+dy*dy > r2) continue;
            dx = x-A; dy = y;
            if (dx*dx+dy*dy > r2) continue;
            dx = x; dy = y-A;
            if (dx*dx+dy*dy > r2) continue;
            dx = x-A; dy = y-A;
            if (dx*dx+dy*dy > r2) continue;
            ret++;
        }
        ret *= a*a * 100000LL / N;
        char S[10];
        sprintf(S, "%d", ret % 100000);
        string r = string(5-strlen(S),'0') + S;
        printf("%d.%s\n", (int)(ret/100000), r.c_str());
    }

    return 0;
}
