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

    int S, N, I;
    double p;
    scanf("%d", &S);
    while (S--) {
        scanf("%d %lf %d", &N, &p, &I);
        if (p < 1E-10) { puts("0.0000"); continue; }
        printf("%.4lf\n", pow(1-p, I-1) * p / (1 - pow(1-p, N)) + 1E-8);
    }

    return 0;
}
