/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    char S[101010];
    while (1) {
        int N = 0;
        char ch;
        while (ch = getchar()) {
            if (ch==EOF) return 0;
            if (ch=='#') { S[N] = 0; break; }
            if (ch=='0'||ch=='1') S[N++] = ch;
        }
        long long ret = 0;
        for (int k = N-1; k >= 0; ) {
            int v = 0, c = 1;
            for (int i = 0; k >= 0 && i < 17; i++) v += (S[k--]-'0')*c, c*=2;
            ret += v;
        }
        if (ret==0 || (ret % 131071 == 0)) puts("YES");
        else puts("NO");
    }

    return 0;
}
