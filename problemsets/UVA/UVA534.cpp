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

int N;
int ADJ[200][200];
int X[200], Y[200];

int main() {

    int T = 1;
    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) scanf("%d %d", X+i, Y+i);
        for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) {
            int dy = Y[i]-Y[j],
                dx = X[i]-X[j];
            ADJ[i][j] = ADJ[j][i] = dy*dy + dx*dx;
        }
        for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            int d = max(ADJ[i][k], ADJ[k][j]);
            if (d < ADJ[i][j]) ADJ[i][j] = d;
        }
        printf("Scenario #%d\n", T++);
        printf("Frog Distance = %.3lf\n\n", sqrt(ADJ[0][1]));
    }

    return 0;
}
