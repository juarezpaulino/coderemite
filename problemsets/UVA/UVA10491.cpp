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

int M, N, K;

int main() {

    while (scanf("%d %d %d", &M, &N, &K) != EOF) {
        double p = N*(M+N-1) / (M+N-K-1.) / (M+N);
        printf("%.5lf\n", p);
    }

    return 0;
}
