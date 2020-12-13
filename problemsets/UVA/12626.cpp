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

    int T;
    scanf("%d", &T);
    while (T--) {
        char S[1010];
        scanf("%s", S);
        int m = 0, a = 0, r = 0, g = 0, i = 0, t = 0;
        for (int k = 0; S[k]; k++)
            if (S[k]=='M') m++;
            else if (S[k]=='A') a++;
            else if (S[k]=='R') r++;
            else if (S[k]=='G') g++;
            else if (S[k]=='I') i++;
            else if (S[k]=='T') t++;
        int ret =   min(m,
                    min(a/3,
                    min(r/2,
                    min(i,
                    min(g,t)))));
        printf("%d\n", ret);
    }

    return 0;
}
