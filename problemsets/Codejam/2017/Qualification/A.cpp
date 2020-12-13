/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

int main() {

    int TT;
    scanf("%d", &TT);
    for (int tt = 1; tt <= TT; tt++) {
        printf("Case #%d: ", t);
        int K;
        char S[1010], ev[1010] = {0};
        scanf("%s %d", S, &K);
        int nS = strlen(S);
        bool ok = 1;
        int ret = 0, k = 0;
        for (int i = 0; S[i]; i++) {
            if (ev[i]) k--;
            if (S[i]=='+' && k%2==0) continue;
            if (S[i]=='-' && k%2) continue;
            if (i > nS-K) {
                if (S[i]=='+' && k%2) ok = 0;
                if (S[i]=='-' && k%2==0) ok = 0;
            }
            else ret++, k++, ev[i+K] = 1;
        }
        if (ok) printf("%d\n", ret);
        else puts("IMPOSSIBLE");
    }

    return 0;
}
