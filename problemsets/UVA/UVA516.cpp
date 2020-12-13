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

inline int POW(int b, int p) {
    if (p==0) return 1;
    int ret = POW(b, p/2);
    ret *= ret;
    if (p%2) ret *= b;
    return ret;
}

typedef map<int, int> prime_map;

void squeeze(prime_map &M, int &n, int p) { for (; n % p == 0; n /= p) M[p]++; }

prime_map factor(int n) {
    prime_map M;
    if (n < 0) return (factor(-n));
    if (n < 2) return M;

    squeeze(M, n, 2); squeeze(M, n, 3);

    int maxP = (int)sqrt(n)+2;
    for (int p = 5; p < maxP; p += 6) { squeeze(M, n, p); squeeze(M, n, p+2); }
    if (n > 1) M[n]++;
    return M;
}


char S[1000];

int main() {

    int t, p, e;
    while (gets(S)) {
        if (*S == '0') break;
        t = 1;
        istringstream is(S);
        while (is >> p >> e) t *= POW(p,e);
        t--;
        prime_map ret = factor(t);
        bool f = false;
        for (prime_map::reverse_iterator it = ret.rbegin(); it != ret.rend(); it++) {
            if (f) putchar(' ');
            f = true;
            printf("%d %d", it->first, it->second);
        }
        putchar('\n');
    }

    return 0;
}
