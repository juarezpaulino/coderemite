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

int N, M;
int T[20];

int main() {

    while (scanf("%d %d", &N, &M) != EOF) {
        for (int i = 0; i < M; i++) scanf("%d", T+i);
        int S = 0, tot = 0;
        for (int s = 0; s < (1<<M); s++) {
            int t = 0;
            for (int i = 0; i < M; i++) if (s&(1<<i)) t+=T[i];
            if (t <= N && (t > tot || (t==tot && __builtin_popcount(s) > __builtin_popcount(S)))) tot = t, S = s;
        }
        for (int i = 0; i < M; i++) if (S&(1<<i)) printf("%d ", T[i]);
        printf("sum:%d\n", tot);
    }

    return 0;
}
