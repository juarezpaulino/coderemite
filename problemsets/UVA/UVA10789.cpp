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

const int MAX = 25000, LMT = sqrt(MAX)+10;
int flag[MAX>>6];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
    int i, j, k;
    for(i = 3; i < LMT; i += 2) if(!ifc(i))
        for(j = i*i, k = i<<1; j < MAX; j += k) isc(j);
}

int F[300];
char S[25000];

int main() {

    sieve();
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        if (scanf("%s", S)==EOF) printf("%d",1/0);
        for (int i = 0; i < 300; i++) F[i] = 0;
        for (int i = 0; S[i]; i++) F[S[i]]++;
        printf("Case %d: ", t);
        bool f = false;
        for (int i = 0; i < 300; i++) {
            if (F[i]==2 || (F[i]%2 && F[i]>2 && !ifc(F[i])))
                putchar(i), f = true;
        }
        if (!f) puts("empty");
        else putchar('\n');
    }

    return 0;
}
