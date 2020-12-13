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

char S[30];

int main() {

    int N;
    while (scanf("%d ", &N)) {
        if (!N) break;
        int ret = 0, m = 100;
        for (int i = 0; i < N; i++) {
            gets(S);
            int k = 0;
            for (int i = 0; S[i]; i++) if (S[i]==' ') k++;
            m = min(m, k);
            ret += k;
        }
        ret -= N*m;
        printf("%d\n", ret);
    }

    return 0;
}
