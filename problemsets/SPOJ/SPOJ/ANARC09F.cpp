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

using namespace std;

const double EPS = 1E-9;

inline int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point {
    double x, y;
    point(double x = 0, double y = 0): x(x), y(y) {}
    point operator -(point q) { return point(x - q.x, y - q.y); }
    double operator *(point q) { return x * q.x + y * q.y; }
};

point pivot;
point P1, P2;
point P[1000];
int N;
double T;
int S1[1000], S2[1000];
int seen[1000];

const double PI = 3.141;

template<class P> double dist(P A, P B = P()) { return sqrt((A-B)*(A-B)); }

inline double area(double R) { return PI * R * R; }

bool comp(const int A, const int B) {
    double d1 = dist(P[A], pivot), d2 = dist(P[B], pivot);
    if (cmp(d1,d2)) return d1 < d2;
    return false;
}

int main() {

    int id = 1;
    while (1) {
        scanf("%d", &N);
        if (!N) break;
        scanf("%lf %lf %lf %lf %lf", &P1.x, &P1.y, &P2.x, &P2.y, &T);
        for (int i = 0; i < N; i++) {
            scanf("%lf %lf", &P[i].x, &P[i].y);
            S1[i] = i; S2[i] = i; seen[i] = 0;
        }
        pivot = P1; sort(S1, S1+N, comp);
        pivot = P2; sort(S2, S2+N, comp);

        int p1 = 0, p2 = 0, c = 0, ret = N;

        while (p1 < N && cmp(area(dist(P1,P[S1[p1]])), T) <= 0) {
            seen[S1[p1]]++; p1++; c++;
        }

        while (p1 >= 0) {

            while (p2 < N && cmp(((p1-1<0) ? 0 : area(dist(P1, P[S1[p1-1]]))) + area(dist(P2, P[S2[p2]])), T) <= 0) {
                if (!seen[S2[p2]]) c++;
                seen[S2[p2]]++; p2++;
            }

            ret = min(ret, N-c);

            if (p1 == 0) break;
            seen[S1[p1-1]]--;
            if (!seen[S1[p1-1]]) c--;
            p1--;
        }

        printf("%d. %d\n", id, ret);
        id++;
    }

    return 0;
}
