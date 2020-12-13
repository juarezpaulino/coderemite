/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll base = 1000000007LL;
const ll mod = 2096725343LL;

char S[2020202];

int main() {

    while (gets(S)) {
        string a = S;
        int n = a.size();
        int i = n-1;
        ll h1 = 0;
        ll h2 = 0;
        ll rbase = 1;
        int p = 0;
        while (i >= 0) {
            h1 = (h1 * base + S[i]) % mod;
            h2 = (h2 + rbase * S[i]) % mod;
            rbase = (rbase * base) % mod;
            if (h1 == h2) p = i;
            i--;
        }
        printf("%s", a.c_str());
        for (int j = p-1; j >= 0; j--) putchar(S[j]);
        putchar('\n');
    }

    return 0;
}
