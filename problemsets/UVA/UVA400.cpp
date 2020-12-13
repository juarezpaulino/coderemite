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
string F[100];
int R, C, L;

int main() {

    char S[100];
    while (scanf("%d", &N)!=EOF) {
        L = 0;
        for (int i = 0; i < N; i++) scanf("%s", S), F[i] = S, L = max(L, (int)strlen(S));
        C = 1 + (60 - L) / (L+2);
        R = (N + C - 1) / C;
        sort(F, F+N);
        for (int i = 0; i < 60; i++) putchar('-'); putchar('\n');
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (j*R+i >= N) printf("%*s", L, "");
                else printf("%-*s", L, F[j*R+i].c_str());
                if (j < C-1) printf("  ");
            }
            putchar('\n');
        }
    }

    return 0;
}
