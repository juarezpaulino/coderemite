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

int N, k;

int main() {

    while (scanf("%d", &N)!=EOF) {
        int ret = k = 0;
        while (N) {
            ret += N;
            int M = (N+k)/3;
            k = (N+k)%3;
            N = M;
        }
        if (k==2) ret++;
        printf("%d\n", ret);
    }

    return 0;
}
