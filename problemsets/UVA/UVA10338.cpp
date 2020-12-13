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

char S[1000];
int N;

unsigned int anagrams(char *S) {
    int N[1000], D[1000];
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
    unsigned int ret = 1;
    for (int i = 0; i < M; i++) ret *= N[i];
    return ret;
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%s", S);
        printf("Data set %d: %u\n", i, anagrams(S));
    }

    return 0;
}
