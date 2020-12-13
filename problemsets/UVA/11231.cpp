/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>

using namespace std;


int main() {

    int N, M, C;
    while (scanf("%d %d %d", &N, &M, &C) && (N|M|C)) {
        int v = (M-7)*(N-7);
        int ret = C && v%2 ? 1 : 0;
        ret += v/2;
        printf("%d\n", ret);
    }

    return 0;
}
