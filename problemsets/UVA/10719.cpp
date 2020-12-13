/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <complex>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

char S[1010101];

const int TAMPOLI = 10101;

struct poly {
    long long p[TAMPOLI]; int n;
    poly(int _n = 0): n(_n) { for (int i = 0; i <= n+1; i++) p[i] = 0; }
    long long& operator [](int i) { return p[i]; }
    pair<poly, long long> ruffini(long long z) {
        if (n == 0) return make_pair(poly(), 0);
        poly r(n-1);
        for (int i = n; i > 0; i--) r[i-1] = r[i] * z + p[i];
        return make_pair(r, r[0] * z + p[0]);
    }
};


int main() {

    long long K, x;
    while (scanf("%lld ", &K) != EOF) {
        gets(S);
        istringstream is(S);
        vector<int> V;
        while (is >> x) V.push_back(x);
        int n = V.size();
        poly P(n);
        for (int i = 0; i < n; i++) P[n-i-1] = V[i];
        pair<poly, long long> ret = P.ruffini(K);
        printf("q(x):");
        for (int i = 0; i < n-1; i++) printf(" %lld", ret.first[P.n-i-2]);
        printf("\nr = %lld\n\n", ret.second);
    }

    return 0;
}
