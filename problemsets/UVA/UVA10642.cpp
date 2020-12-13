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
#include <numeric>

using namespace std;


int main() {

    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        long long A = (y1+x1)*(long long)(y1+x1+1)/2 + y1 + 1;
        long long B = (y2+x2)*(long long)(y2+x2+1)/2 + y2 + 1;
        printf("Case %d: %lld\n", t, B-A);
    }

    return 0;
}
