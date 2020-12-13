/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int N, K;
int R[1010];

int main() {

    scanf("%d %d", &N, &K);
    int x;
    while (N--) { scanf("%d", &x); R[x]++; }
    int ret = *min_element(R+1, R+K+1);
    printf("%d\n", ret);

    return 0;
}
