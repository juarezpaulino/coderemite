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

int ADJ[100][100];
int N;

const int INF = 0x3F3F3F3F;

char S[10];

int main() {

    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) ADJ[i][j] = (i==j) ? 0 : INF;
        for (int i = 1; i < N; i++) for (int j = 0; j < i; j++) {
            scanf("%s", S);
            if (*S=='x') continue;
            ADJ[j][i] = ADJ[i][j] = atoi(S);
        }
        for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
            int d = ADJ[i][k] + ADJ[k][j];
            if (d < ADJ[i][j]) ADJ[i][j] = d;
        }
        int ret = 0;
        for (int i = 1; i < N; i++) ret = max(ret, ADJ[0][i]);
        printf("%d\n", ret);
    }

    return 0;
}
