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

    while (1) {
        int a, b, d = 0;
        scanf("%d", &a);
        if (!a) break;
        while (1) {
            scanf("%d", &b);
            if (!b) break;
            d = __gcd(d, abs(a-b));
            a = b;
        }
        printf("%d\n", d);
    }

    return 0;
}
