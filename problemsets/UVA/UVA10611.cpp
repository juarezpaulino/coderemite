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

int H[50000];
int N, Q;

int main() {

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", H+i);
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int h;
        scanf("%d", &h);
        int *l = lower_bound(H,H+N,h)-1;
        int *u = upper_bound(H,H+N,h);
        ((l >= H)  ? printf("%d ", *l)  : printf("X "));
        ((u < H+N) ? printf("%d\n", *u) : printf("X\n"));
    }

    return 0;
}
