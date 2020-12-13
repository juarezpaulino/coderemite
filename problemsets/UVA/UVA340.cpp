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

int A[1000], B[1000], F[1000];
int N;

int main() {

    int T = 1;
    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) scanf("%d", A+i);
        printf("Game %d:\n", T++);
        while (1) {
            for (int i = 0; i < N; i++) scanf("%d", B+i), F[i] = 0;
            if (*B==0) break;
            map<int,int> IN;
            int s = 0, w = 0;
            for (int i = 0; i < N; i++) if (A[i]==B[i]) s++, F[i] = 1; else IN[A[i]]++;
            for (int i = 0; i < N; i++) if (!F[i] && IN[B[i]]) w++, IN[B[i]]--;
            printf("    (%d,%d)\n", s, w);
        }
    }

    return 0;
}
