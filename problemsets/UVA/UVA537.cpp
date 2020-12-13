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

int T;
char S[1000], S2[100];
double NP, NI, NU;

int main() {

    scanf("%d ", &T);
    for (int t = 1; t <= T; t++) {
        printf("Problem #%d\n", t);
        gets(S);
        int P = string(S).find("P=");
        if (P != -1) {
            int k = 0, i;
            for (i = P+2; S[i]=='.' || (S[i]>='0' && S[i]<='9'); i++) S2[k++] = S[i];
            S2[k] = 0;
            sscanf(S2,"%lf",&NP);
            if (S[i]=='m') NP/=1000;
            else if (S[i]=='k') NP*=1000;
            else if (S[i]=='M') NP*=1000000;
        }
        int I = string(S).find("I=");
        if (I != -1) {
            int k = 0, i;
            for (i = I+2; S[i]=='.' || (S[i]>='0' && S[i]<='9'); i++) S2[k++] = S[i];
            S2[k] = 0;
            sscanf(S2,"%lf",&NI);
            if (S[i]=='m') NI/=1000;
            else if (S[i]=='k') NI*=1000;
            else if (S[i]=='M') NI*=1000000;
        }
        int U = string(S).find("U=");
        if (U != -1) {
            int k = 0, i;
            for (i = U+2; S[i]=='.' || (S[i]>='0' && S[i]<='9'); i++) S2[k++] = S[i];
            S2[k] = 0;
            sscanf(S2,"%lf",&NU);
            if (S[i]=='m') NU/=1000;
            else if (S[i]=='k') NU*=1000;
            else if (S[i]=='M') NU*=1000000;
        }
        if (P==-1) printf("P=%.2lfW\n\n", NI * NU);
        else if (I==-1) printf("I=%.2lfA\n\n", NP / NU);
        else printf("U=%.2lfV\n\n", NP / NI);
    }

    return 0;
}
