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

vector<int> S;
int V[1000];
int N, Q;

int main() {

    int T = 1;
    while (scanf("%d", &N)) {
        if (!N) break;
        int M = (N*(N-1))/2;
        S.resize(M);
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        for (int i = 0, k = 0; i < N; i++) for (int j = i+1; j < N; j++) S[k++] = V[i]+V[j];
        sort(S.begin(), S.end());
        scanf("%d", &Q);
        printf("Case %d:\n", T++);
        while (Q--) {
            int s;
            scanf("%d", &s);
            vector<int>::iterator i1, i2;
            i2 = lower_bound(S.begin(), S.end(), s);
            i1 = i2; i1--;
            int ret = 0x3F3F3F3F, d = ret;
            if (i2 != S.end()) ret = *i2, d = abs(*i2-s);
            if (i2 != S.begin() && abs(*i1-s) < d) ret = *i1;
            printf("Closest sum to %d is %d.\n", s, ret);
        }
    }

    return 0;
}
