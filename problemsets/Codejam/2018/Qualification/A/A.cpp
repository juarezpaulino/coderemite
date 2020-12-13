/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    int TT;
    scanf("%d", &TT);
    for (int tt = 1; tt <= TT; tt++) {
        printf("Case #%d: ", tt);

        int D;
        string S;
        cin >> D >> S;

        ll t = 0, c = 1;
        for (int i = 0; i < S.length(); i++)
            if (S[i]=='S') t += c;
            else c <<= 1;

        bool r = 1;
        int ret = 0;
        while (t > D && r) {
            r = 0;
            ll c1 = c;
            int k = S.length()-1;
            while (k >= 0 && S[k]=='C') k--, c1>>=1;
            while (k >= 0 && S[k]=='S') k--;
            if (k >= 0 && k < S.length() && S[k]=='C' && S[k+1]=='S')
                swap(S[k], S[k+1]), t -= c1>>1, r = 1;
            ret++;
        }
        if (!r) puts("IMPOSSIBLE");
        else printf("%d\n", ret);
    }
    return 0;
}
