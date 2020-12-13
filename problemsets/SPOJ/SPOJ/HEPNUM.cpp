/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    char S[101010], T[101010];
    int M, N;
    string s, t;

    while (1) {
        scanf("%s %s", S, T);
        if (*S == '*') break;
        M = strlen(S), N = strlen(T);
        s = S; t = T;
        if (M < N) s = string(N-M, '0') + s;
        if (N < M) t = string(M-N, '0') + t;
        if (s < t) printf("<\n");
        else if (s > t) printf(">\n");
        else printf("=\n");
    }

    return 0;
}
