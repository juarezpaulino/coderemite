/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int a, b, M;
    while (scanf("%d", &a)) {
        if (!a) break;
        vector<int> V, W;
        int w = 1;
        M = 1;
        while (scanf("%d", &b)) {
            if (b != a) V.push_back(a), W.push_back(w), w = 1;
            else w++;
            if (!b) break;
            M++;
            a = b;
        }
        int N = V.size();
        if (N == 1) { printf("Nr values = %d:  0.000000 0.000000\n", M); continue; }
        int u = 0, nu = 0,
            d = 0, nd = 0,
            up = (V[1] > V[0]) ? (u = -1, 1) : (d = -1, 0);
        for (int i = 0; i < N; i++) {
            if (up) {
                if (i == 0 || V[i] > V[i-1]) u += W[i];
                else up = 0, d += W[i], nu++;
            }
            else {
                if (i == 0 || V[i] < V[i-1]) d += W[i];
                else up = 1, u += W[i], nd++;
            }
        }
        if (up) nu++;
        else nd++;
        printf("Nr values = %d:  %.6lf %.6lf\n", M, (!nu) ? 0 : u / (double) nu, (!nd) ? 0 : d / (double) nd);
    }

    return 0;
}
