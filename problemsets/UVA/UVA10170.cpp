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

int S;
long long D;


int main() {

    while (scanf("%d %lld", &S, &D) != EOF) {
        double B = 2.*S - 1;
        double delta = B*B + 8*D;
        int N = ( -B + sqrt(delta) ) / 2. + 1 - 1E-8;
        printf("%d\n", S+N-1);
    }

    return 0;
}
