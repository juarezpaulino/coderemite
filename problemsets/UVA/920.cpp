/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct point { int x, y; };

bool comp(const point &A, const point &B) {
    if (A.x != B.x) return A.x > B.x;
    return A.y > B.y;
}

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        vector<point> V(N, (point){0,0});
        for (int i = 0; i < N; i++) scanf("%d %d", &V[i].x, &V[i].y);
        sort(V.begin(), V.end(), comp);
        int H = 0;
        double ret = 0;
        for (int i = 0; i < N-1; i++) {
            if (V[i+1].y > H) {
                int dx = V[i].x-V[i+1].x;
                int dy = V[i].y-V[i+1].y;
                ret += sqrt(dx*dx+dy*dy) * (V[i+1].y-H) / (V[i+1].y-V[i].y);
                H = V[i+1].y;
            }
        }
        printf("%.2lf\n", ret);
    }

    return 0;
}
