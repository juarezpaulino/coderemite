/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int INF = (1<<30);

const int MAXV = 700;

struct Point { int x, y; };

Point p[MAXV];

void normal(int x0, int y0, int x1, int y1, int &x2, int &y2) {
    int a = abs(x2 = x1-x0), b = abs(y2 = y1-y0);
    if (a==0) { y2 = 1; return; }
    if (b==0) { x2 = INF; return; }
    a = __gcd(a, b); x2/=a; y2/=a;
    if (x2 < 0) x2*=-1, y2*=-1;
}

int compute(int n) {
    int maxi = 1, x, y;
    if (n <= 2) return n;
    while (n-- > 2) {
        map<pair<int, int>, int> mapa;
        for (int i = 0; i < n; i++) {
            normal(p[n].x, p[n].y, p[i].x, p[i].y, x, y);
            maxi = max(maxi, (++mapa[make_pair(x, y)]));
        }
    }
    return maxi+1;
}


int main() {

    int T;
    char S[1010];
    scanf("%d ", &T);
    while (T--) {
        int x, y;
        int N = 0;
        while (gets(S)) {
            if (*S == 0) break;
            sscanf(S, "%d %d", &x, &y);
            p[N++] = (Point){x,y};
        }
        int ret = compute(N);
        printf("%d\n", ret);
        if (T) putchar('\n');
    }

    return 0;
}
