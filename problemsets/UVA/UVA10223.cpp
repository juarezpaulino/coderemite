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

map<int,int> RET;

unsigned ncc_mod(unsigned n, unsigned k) {
    unsigned num[k], den[k];
    for (unsigned i = 0; i < k; i++) num[i] = n - i, den[i] = i + 1;
    den[k] = k + 1;
    for (unsigned i = 0; i < k+1; i++) for (unsigned j = 0; j < k; j++) {
        unsigned mdc = __gcd(den[i], num[j]);
        num[j] /= mdc; den[i] /= mdc;
    }
    long long ret = 1;
    for (unsigned i = 0; i < k; i++) ret = (ret*num[i]);
    return ret;
}

int N;

int main() {

    RET[1] = 1;
    for (int i = 2; i < 20; i++) RET[ncc_mod(2*i,i)] = i;

    while (scanf("%d", &N)!=EOF) {
        printf("%d\n", RET[N]);
    }

    return 0;
}
