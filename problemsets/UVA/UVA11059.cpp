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

int N;
int V[20];

int main() {

    int T = 1;
    while (scanf("%d", &N) != EOF) {
        for (int i = 0; i < N; i++) scanf("%d", V+i);
        long long ret = 0, A = 0, B = 0;
        for (int i = 0; i < N; i++) {
            if (V[i]==0) A = B = 0;
            else if (V[i] < 0) {
                long long X = A*V[i];
                A = B*V[i];
                B = (X) ? X : V[i];
            }
            else {
                A = (A) ? A*V[i] : V[i];
                B = B*V[i];
            }
            ret = max(ret, A);
        }
        printf("Case #%d: The maximum product is %lld.\n\n", T++, ret);
    }

    return 0;
}
