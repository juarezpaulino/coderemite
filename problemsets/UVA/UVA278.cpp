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

char MAPA[10][10];

char C;
int M, N;

int main() {

    int T;
    scanf("%d ", &T);
    while (T--) {
        scanf("%c %d %d ", &C, &M, &N);
        int ret = 0;
        if (C == 'r' || C == 'Q') ret = min(M,N);
        if (C == 'k') ret = (M*N+1)/2;
        if (C == 'K') ret = ((M+1)/2) * ((N+1)/2);
        printf("%d\n", ret);
    }

    return 0;
}
