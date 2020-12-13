/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <inttypes.h>
#include <ctype.h>
#include <algorithm>
#include <utility>
#include <iostream>
#include <vector>


using namespace std;

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << "\n")
#define _inline(f...) f() __attribute__((always_inline)); f
#define _foreach(it, b, e) for (typeof(b) it = (b); it != (e); it++)
#define foreach(x...) _foreach(x)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

const int INF = 0x3F3F3F3F;
const int NULO = -1;
const double EPS = 1e-13;


struct point {
    int x, y;
    point(int x = 0, int y = 0): x(x), y(y) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    int operator *(point q) { return x * q.x + y * q.y; }
    int operator %(point q) { return x * q.y - y * q.x; }
};

////////////////////////////////////////////////////////////////////////////////
// Retorna <0, 0, >0 para cw, colinear, ccw
//
_inline(int ccw)(point p, point q, point r) {
    return (p - r) % (q - r);
}

int cmp(const void *a, const void *b) {
    point *p1 = (point *)a, *p2 = (point *)b;
    return *p2%*p1;
}


int main() {
    
    int n, x, y;
    register int i, j, k, c = 1, win;
    point v[210];
    int dp[210][210];
    
    while (scanf("%d", &n) && n) {
        v[0] = point(0, 0);
        for (i = 1; i <= n; i++) { scanf("%d %d", &x, &y); v[i] = point(x, y); }
        // Ordena os pontos pelo angulo em sentido anti-horario
        qsort(&v[1], n, sizeof(point), cmp);
        win = 0; dp[0][0] = 1;
        for (i = 1; i <= n; i++) { dp[i][0] = 2;
            for (j = 1; j < i; j++) { dp[i][j] = 0;
                for (k = 0; k < j; k++)
                    if (dp[j][k] >= dp[i][j] && ccw(v[k], v[j], v[i]) > 0)
                        dp[i][j] = dp[j][k]+1;
                if (dp[i][j] > win) win = dp[i][j];
            }
        }
        printf("Teste %d\n%d\n\n", c++, win);
    }
    
    return 0;
}

