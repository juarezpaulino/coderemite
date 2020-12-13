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

    int N;
    while (scanf("%d", &N) != EOF) {
        int e = N * log10(2) + 1.;
        double r = pow(2,e / log10(2) - N);
        printf("2^-%d = %.3lfe-%d\n", N, r, e);
    }

    return 0;
}
