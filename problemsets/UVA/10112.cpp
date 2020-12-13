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
#include <map>
#include <string>

using namespace std;

inline int cmp(int x, int y = 0) {
    return (x <= y) ? (x < y) ? -1 : 0 : 1;
}

struct point {
    int x, y;
    point(int x = 0, int y = 0): x(x), y(y) {}
    point operator +(point q) { return point(x + q.x, y + q.y); }
    point operator -(point q) { return point(x - q.x, y - q.y); }
    point operator *(int t) { return point(x * t, y * t); }
    int operator *(point q) { return x * q.x + y * q.y; }
    int operator %(point q) { return x * q.y - y * q.x; }
    int cmp(point q) const {
        if (int t = ::cmp(x, q.x)) return t;
        return ::cmp(y, q.y);
    }
};

inline int signed_area(point &p, point &q, point &r) {
    return (p - r) % (q - r);
}

inline int ccw(point &p, point &q, point &r) {
    return cmp((p - r) % (q - r));
}

int main() {

    int N;
    point P[14];
    while (scanf("%d", &N)) {
        if (!N) break;
        map<int,char> M;
        char c;
        for (int i = 0; i < N; i++) scanf(" %c %d %d", &c, &P[i].x, &P[i].y), M[i] = c;
        string best;
        int area = 0;
        for (int k = 0; k < N; k++) for (int i = k+1; i < N; i++) for (int j = i+1; j < N; j++) {
            bool ok = 1;
            for (int l = 0; l < N; l++) if (l!=k&&l!=i&&l!=j) {
                int d = ccw(P[k], P[i], P[j]);
                bool in = ccw(P[k],P[i],P[l]) != -d &&
                          ccw(P[i],P[j],P[l]) != -d &&
                          ccw(P[j],P[k],P[l]) != -d;
                ok &= !in;
            }
            if (!ok) continue;
            int a = abs(signed_area(P[k],P[i],P[j]));
            string r = string(1,M[k]) + string(1,M[i]) + string(1,M[j]);
            sort(r.begin(), r.end());
            if (a > area || (a==area && r < best)) best = r, area = a;
        }
        puts(best.c_str());
    }

    return 0;
}
