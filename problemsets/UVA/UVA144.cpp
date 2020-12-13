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

int N, k;

int tot[25];
int V[25];

int main() {

    while (scanf("%d %d", &N, &k)) {
        if (!(N|k))  break;
        int M = N, K = -1, p = 0, s = 0;
        for (int i = 0; i < N; i++) V[i] = i+1;
        for (int i = 0; i < N; i++) tot[i] = 0;
        while (M) {
            if (s == 0) { K = (K+1)%k; s = K+1; }
            tot[p] += s;
            s = (tot[p] > 40) ? tot[p]%40 : 0;
            if (tot[p] >= 40) {
                printf("%3d", V[p]);
                copy(V+p+1, V+M, V+p);
                copy(tot+p+1, tot+M, tot+p);
                M--;
                if (p == M) p = 0;
            }
            else p = (p+1)%M;
        }
        putchar('\n');
    }

    return 0;
}
