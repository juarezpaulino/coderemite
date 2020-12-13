/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

char isPrime(int n) {
    int maxP, p;
    if (n < 0) return isPrime(-n);
    if (n < 5 || n%2 == 0 || n%3 == 0) return (n == 2 || n == 3);
    maxP = (int)sqrt(n)+2;
    for (p = 5; p < maxP; p += 6) if (n % p == 0 || n % (p+2) == 0) return 0;
    return 1;
}

int main() {

    int N;
    while (scanf("%d", &N) != EOF) {
        for (int i = N; ; i++) {
            if (!isPrime(i) && !isPrime(i+2)) {
                printf("%d\n", i);
                break;
            }
        }
    }

    return 0;
}
