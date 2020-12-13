/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
///////////////////////////////////////////////////////////////////////////////
// RANK OF A PERMUTATION
//
// Count anagrams recursively for each S+k+1 | S[i] < S[k], k+1 <= i < N.
// If a letter S[i] < S[k], it would be used before S[k] on the sequence.
//
///////////////////////////////////////////////////////////////////////////////

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
#include <numeric>

using namespace std;

char S[50];
int N;

long long anagrams(char *S) {
    int N[50], D[50];
    int C[300] = {0};
    int K = 0, M = strlen(S);
    for (int i = 0; i < M; i++) {
        C[S[i]]++;
        if (C[S[i]] > 1) D[K++] = C[S[i]];
    }
    for (int i = 0; i < M; i++) N[i] = i+1;
    for (int k = 0; k < K; k++) for (int i = 0; i < M; i++) {
        int d = __gcd(N[i], D[k]);
        N[i] /= d; D[k] /= d;
    }
    long long ret = 1;
    for (int i = 0; i < M; i++) ret *= N[i];
    return ret;
}

int go(int k) {
    set<int> I;
    if (k == N) return 0;
    long long ret = 0;
    for (int i = k+1; S[i]; i++) if (S[i] < S[k] && !I.count(S[i])) {
        I.insert(S[i]);
        swap(S[k], S[i]);
        ret += anagrams(S+k+1);
        swap(S[k], S[i]);
    }
    ret += go(k+1);
    return ret;
}

int main() {

    while (gets(S)) {
        if (!strcmp(S,"#")) break;
        N = strlen(S);
        long long ret = go(0);
        printf("%10lld\n", ret+1);
    }

    return 0;
}
