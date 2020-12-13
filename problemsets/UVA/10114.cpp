/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>

using namespace std;


int main() {

    int N, M;
    double D, L;

    while (scanf("%d %lf %lf %d", &N, &D, &L, &M) && N >= 0) {
        int x;
        double t, t2;
        scanf("%*d %lf", &t);
        double V = L + D;
        double d = L / N;
        V -= t*V;
        int ret = 1;
        bool ok = (L >= V) ? 1 : 0;
        while (--M) {
            scanf("%d %lf", &x, &t2);
            while (ok && ret < x) {
                V -= t*V;
                L -= d;
                ++ret;
                if (L < V) { ok = 0; break; }
            }
            t = t2;
        }
        while (ok) {
            V -= t*V;
            L -= d;
            ++ret;
            if (L < V) { ok = 0; break; }
        }
        printf("%d month%s\n", ret-1, (ret-1 == 1) ? "" : "s");
    }

    return 0;
}
