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

typedef long long i64;

int A, B;

int main() {

    int T = 1;
    while (scanf("%d %d", &A, &B)) {
        if (!(A|B)) break;
        i64 ret = 0;
        ret = A*(A-1)/2 * (i64)(B*(B-1)/2);
        printf("Case %d: %lld\n", T++, ret);
    }

    return 0;
}
