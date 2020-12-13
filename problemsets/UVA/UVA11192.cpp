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
int G;

int main() {

    while (scanf("%d %s", &G, S) != EOF) {
        if (!G) break;
        int k = 0, L = strlen(S)/G;
        char W[110];
        for (int i = 0; S[i]; i++) {
            W[k++] = S[i];
            if (k == L) {
                W[k] = 0;
                reverse(W,W+k);
                printf(W);
                k = 0;
            }
        }
        putchar('\n');
    }

    return 0;
}
