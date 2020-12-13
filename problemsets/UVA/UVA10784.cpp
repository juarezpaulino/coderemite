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

long long int N;

int main() {

    int T = 1;
    while (scanf("%lld", &N)) {
        if (!N) break;
        int u = 0, v = 100000000;
        while (u < v) {
            long long m = (u+v)/2;
            if ((m-3)*(m)/2 < N) u = m+1;
            else v = m;
        }
        printf("Case %d: %d\n", T++, u);
    }

    return 0;
}
