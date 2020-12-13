/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int M[1030][1030];
int Y[20202], X[20202], P[20202];
int Xmin, Ymin, Xmax, Ymax;

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int D, N;
        scanf("%d %d", &D, &N);
        if (N == 0) { puts("0 0 0"); continue; }
        Xmin = Ymin = 1024;
        Xmax = Ymax = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", X+i, Y+i, P+i);
            Xmin = min(Xmin, max(0,X[i]-D)); Xmax = max(Xmax, min(1024,X[i]+D));
            Ymin = min(Ymin, max(0,Y[i]-D)); Ymax = max(Ymax, min(1024,Y[i]+D));
        }
        for (int i = Xmin; i <= Xmax; i++) for (int j = Ymin; j <= Ymax; j++) M[i][j] = 0;
        int Xbest = 0, Ybest = 0, Pbest = 0;
        for (int k = 0; k < N; k++) {
            for (int i = max(0,X[k]-D); i <= min(1024,X[k]+D); i++) for (int j = max(0,Y[k]-D); j <= min(1024,Y[k]+D); j++)
                M[i][j] += P[k];
        }
        for (int i = Xmin; i <= Xmax; i++) for (int j = Ymin; j <= Ymax; j++)
            if (M[i][j] > Pbest)
                Pbest = M[i][j], Xbest = i, Ybest = j;
        printf("%d %d %d\n", Xbest, Ybest, Pbest);
    }

    return 0;
}
