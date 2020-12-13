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

char S[10000];
int N;

bool comp(const char &A, const char &B) {
    if (toupper(A) != toupper(B)) return toupper(A) < toupper(B);
    return A < B;
}

int main() {

    scanf("%d", &N);
    while (N--) {
        scanf("%s", S);
        int M = strlen(S);
        sort(S,S+M, comp);
        do {
            puts(S);
        } while (next_permutation(S, S+M, comp));
    }

    return 0;
}
