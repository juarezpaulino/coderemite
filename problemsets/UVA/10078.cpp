/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double EPS = 1E-14;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}
    point operator -(point q) { return point(x - q.x, y - q.y); }
    double operator %(point q) { return x * q.y - y * q.x; }
};


inline int ccw(point p, point q, point r) {
    return cmp((p - r) % (q - r));
}

point P[55];

int main() {

    int N;
    while (scanf("%d", &N) != EOF) {
        if (N == 0) break;
        for (int i = 0; i < N; i++) scanf("%lf %lf", &P[i].x, &P[i].y);
        int ret = 0;
        for (int i = 0; i < N; i++) {
            int k = (i+N-1)%N, j = (i+1)%N;
            ret += ccw(P[k], P[i], P[j]);
        }
        if (ret != N && ret != -N) puts("Yes");
        else puts("No");
    }

    return 0;
}
