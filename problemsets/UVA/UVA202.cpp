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

int M, N;
char S[10];
int MOD[3010];
int v[3010];

int main() {

    while (scanf("%d %d", &M, &N) != EOF) {
        string n, m;
        memset(MOD,0,sizeof(MOD));
        printf("%d/%d = ", M, N);
        sprintf(S, "%d", M/N); n += S; M %= N;
        n += ".";
        while (!MOD[M]) {
            v[m.size()] = M;
            MOD[M] = 1;
            M *= 10; sprintf(S, "%d", M/N); m += S; M %= N;
        }
        string ret;
        int k, l;
        for (k = 0; v[k] != M; k++) ret += m[k];
        l = m.size() - k;
        ret += "(" + ((l > 50) ? m.substr(k, 50)+"..." : m.substr(k)) + ")";
        printf("%s", n.c_str());
        printf("%s\n", ret.c_str());
        printf("   %d = number of digits in repeating cycle\n\n", l);
    }

    return 0;
}
