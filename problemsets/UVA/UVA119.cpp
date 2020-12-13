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
#include <queue>

using namespace std;

map<string, int> M;
string P[100];
int V[100];
int N;

int main() {

    char S[20];
    bool f = false;
    while (scanf("%d", &N) != EOF) {
        if (f) putchar('\n');
        f = true;

        M.clear();
        for (int i = 0; i < N; i++) {
            scanf("%s", S);
            M[S] = i; P[i] = S;
            V[i] = 0;
        }

        for (int i = 0; i < N; i++) {
            int x, k, p;
            scanf("%s %d %d", S, &x, &k);
            p = M[S];
            if (k) x /= k;
            while (k--) {
                scanf(" %s ", S);
                V[M[S]] += x; V[p] -= x;
            }
        }

        for (int i = 0; i < N; i++) printf("%s %d\n", P[i].c_str(), V[i]);
    }

    return 0;
}
