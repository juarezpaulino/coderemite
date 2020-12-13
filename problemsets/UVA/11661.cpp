/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;


int main() {

    int L;
    char S[2020202];
    while (scanf("%d ", &L)) {
        if (!L) break;
        gets(S);
        int ret = (1<<30), ld = -1, lr = -1;
        for (int i = 0; S[i]; i++) {
            if (S[i]=='Z') { ret = 0; break; }
            if (S[i]=='D') {
                if (lr != -1) ret = min(ret, i-lr);
                ld = i;
            }
            if (S[i]=='R') {
                if (ld != -1) ret = min(ret, i-ld);
                lr = i;
            }
        }
        printf("%d\n", ret);
    }

    return 0;
}
