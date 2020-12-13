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

    int T, N;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        N = (N*567);
        N = (N/9);
        N = (N+7492);
        N = (N*235);
        N = (N/47);
        N = (N-498);
        N /= 10;
        N %= 10;
        printf("%d\n", abs(N));
    }

    return 0;
}
