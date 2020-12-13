/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cmath>
#include <stack>
#include <algorithm>
#include <map>

#define _FORIT(it, b, e) for (__typeof(b) it = (b); it != (e); it++)
#define FORIT(x...) _FORIT(x)
#define IT(v) __typeof((v).begin())
#define ALL(v) (v).begin(), (v).end()


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

    int A, B;

    int id = 1;
    while (scanf("%d %d", &A, &B) != EOF) {
        if (!A && !B) break;

        prime_map M1 = factor(A);
        prime_map M2 = factor(B);

        int N = 0, ret = 0;
        IT(M1) it1 = M1.begin(), it2 = M2.begin();
        while (it1 != M1.end() && it2 != M2.end()) {
            if (it1->first < it2->first) { N++; ret+=it1->second; it1++; }
            else if (it2->first < it1->first) { N++; ret+=it2->second; it2++; }
            else { N++; ret+=abs(it2->second-it1->second); it1++; it2++; }
        }
        while (it1 != M1.end()) { N++; ret+=it1->second; it1++; }
        while (it2 != M2.end()) { N++; ret+=it2->second; it2++; }

        printf("%d. %d:%d\n", id, N, ret);
        id++;
    }

    return 0;
}
