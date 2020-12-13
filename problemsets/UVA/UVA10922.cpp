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

char S[1010];

int main() {

    while (scanf("%s", S)) {
        if (!strcmp(S,"0")) break;
        int N = 0;
        for (int i = 0; S[i]; i++) N += S[i]-'0';
        int D = 1;
        while (N > 9) {
            int M = 0;
            while (N) { M+=N%10; N/=10; }
            N = M;
            D++;
        }
        if (N == 9) printf("%s is a multiple of 9 and has 9-degree %d.\n", S, D);
        else printf("%s is not a multiple of 9.\n", S);
    }

    return 0;
}
