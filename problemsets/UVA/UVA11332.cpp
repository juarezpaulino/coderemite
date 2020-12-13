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

int N;

int main() {

    while (scanf("%d", &N)) {
        if (!N) break;
        while (N >= 10) {
            int M = 0;
            while (N) { M += N%10; N/=10; }
            N = M;
        }
        printf("%d\n", N);
    }

    return 0;
}
