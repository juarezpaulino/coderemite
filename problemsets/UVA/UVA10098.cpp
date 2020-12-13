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

char S[15];

int main() {

    int N;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", S);
        int M = strlen(S);
        sort(S, S+M);
        do {
            puts(S);
        } while (next_permutation(S, S+M));
        putchar('\n');
    }

    return 0;
}
