/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>

using namespace std;

long long DP[310][310];

long long go(int v, int k) {
    long long &ret = DP[v][k];
    if (ret != -1) return ret;
    if (v == 0) return ret = 1;
    ret = 0;
    if (v - k >= 0) ret += go(v-k,k);
    if (k-1 > 0) ret += go(v,k-1);
    return ret;
}

char S[101010];


int main() {

    memset(DP, -1, sizeof(DP));
    while (gets(S)) {
        if (*S == 0) continue;
        int N, L1 = -1, L2 = -1;
        int c = sscanf(S, "%d %d %d", &N, &L1, &L2);
        long long ret = 0;
        if (c == 1) ret = go(N,N);
        else if (c == 2) {
            if (L1 > N) L1 = N;
            ret = go(N,L1);
        }
        else {
            if (L1 > N) ret = 0;
            else {
                if (L1 > N) L1 = N;
                if (L2 > N) L2 = N;
                ret = go(N,L2) - ((L1 > 0) ? go(N,L1-1) : 0);
            }
        }
        printf("%lld\n", ret);
    }

    return 0;
}
