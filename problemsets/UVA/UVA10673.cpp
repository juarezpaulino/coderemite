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

pair<int, int> find_bezout(int x, int y) {
    if (!y) return pair<int, int>(1, 0);
    pair<int, int> u = find_bezout(y, x%y);
    return pair<int, int>(u.second, u.first - (x/y)*u.second);
}


int main() {

    int T;
    scanf("%d", &T);
    while (T--) {
        int x, k;
        scanf("%d %d", &x, &k);
        if (x%k == 0) { printf("0 %d\n", k); continue; }
        int A = x/k;
        pair<int,int> p = find_bezout(A, A+1);
        printf("%d %d\n", p.first * x, p.second * x);
    }

    return 0;
}
