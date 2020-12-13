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

char L[3][50], R[3][50], G[3][50];
int P[12] = {0};

int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 3; i++) scanf("%s %s %s", L[i], R[i], G[i]);
        int ret = -1, v = 0;
        for (int i = 0; i < 12; i++) for (int p = -1; p < 2; p+=2) {
            P[i] = p;
            bool ok = 1;
            for (int k = 0; ok && k < 3; k++) {
                int l = 0, r = 0;
                for (int j = 0; L[k][j]; j++) l += P[L[k][j]-'A'];
                for (int j = 0; R[k][j]; j++) r += P[R[k][j]-'A'];
                if (!( (G[k]==string("even") && l==r) ||
                       (G[k]==string("up") && l > r)  ||
                       (G[k]==string("down") && l < r) )) ok = 0;
            }
            P[i] = 0;
            if (ok) { ret = i; v = p; break; }
        }
        printf("%c is the counterfeit coin and it is %s.\n", ret+'A', (v==-1) ? "light" : "heavy");
    }

    return 0;
}
