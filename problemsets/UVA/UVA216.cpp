/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

int X[8], Y[8];
int N;
int P[8], B[8];

int main() {

    int T = 1;
    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) scanf("%d %d", X+i, Y+i), P[i] = i;
        double ret = 1E10;
        do {
            double t = 0;
            for (int i = 1; i < N; i++) {
                int dy = Y[P[i]]-Y[P[i-1]];
                int dx = X[P[i]]-X[P[i-1]];
                t += sqrt(dy*dy + dx*dx) + 16.;
            }
            if (t < ret-1E-10) { ret = t; copy(P, P+N, B); }
        } while (next_permutation(P, P+N));
        printf("**********************************************************\n");
        printf("Network #%d\n", T++);
        for (int i = 1; i < N; i++) {
            int dy = Y[B[i]]-Y[B[i-1]];
            int dx = X[B[i]]-X[B[i-1]];
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", X[B[i-1]], Y[B[i-1]], X[B[i]], Y[B[i]], sqrt(dx*dx+dy*dy)+16.);
        }
        printf("Number of feet of cable required is %.2lf.\n", ret);
    }

    return 0;
}
