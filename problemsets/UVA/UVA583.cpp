/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

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


int main() {

    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        ostringstream o;
        o << N << " =";
        if (N < 0) o << " -1 x", N = -N;
        prime_map M = factor(N);
        for (prime_map::iterator it = M.begin(); it != M.end(); it++)
            for (int i = 0; i < it->second; i++) {
                o << " " << it->first << " x";
            }
        string s = o.str();
        s = s.substr(0,s.size()-2);
        printf("%s\n", s.c_str());
    }

    return 0;
}
