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

    int T;
    scanf("%d", &T);
    while (T--) {
        int M, N;
        scanf("%d %d", &M, &N);
        printf("%d\n", (M/3)*(N/3));
    }

    return 0;
}
