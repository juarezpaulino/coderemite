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


int main() {

    long long N, K;
    double sum;
    while (scanf("%lld %lld", &N, &K) != EOF) {
        sum = 0.;
        if (K > N-K) K = N-K;
        for (long long i = N - K + 1; i <= N; i++) sum += log10(i)-log10(N - i + 1);
        sum = floor(sum) + 1.;
        printf("%.0lf\n", sum);
    }

    return 0;
}
