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

const int MAXV = 1000010;
const int MAXVV = sqrt(MAXV)+1;

char pr[MAXV];

void sieve() {
    for (int i = 4; i < MAXV; i+=2) pr[i] = 1;
    for (int i = 3; i < MAXVV; i+=2) if (!pr[i])
        for (int j = 3*i; j < MAXV; j+=2*i) pr[j] = 1;
}

int N;

int main() {

    sieve();
    while (scanf("%d", &N) != EOF) {
        if (N==1) { printf("%d is prime.\n", N); continue; }
        if (N==2) { printf("%d is prime.\n", N); continue; }
        int M;
        char S[100];
        sprintf(S, "%d", N);
        reverse(S, S+strlen(S));
        M = atoi(S);
        if (M!=N && !pr[N] && !pr[M]) { printf("%d is emirp.\n", N); continue; }
        if (!pr[N]) { printf("%d is prime.\n", N); continue; }
        printf("%d is not prime.\n", N);
    }

    return 0;
}
