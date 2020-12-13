/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main() {

    int A[101010];
    int N;
    while (scanf("%d", &N)) {
        if (!N) break;
        for (int i = 0; i < N; i++) scanf("%d", A+i);
        long long sum = 0, ret = 0;
        for (int i = 0; i < N-1; i++) {
            sum += A[i];
            ret += abs(sum);
        }
        printf("%lld\n", ret);
    }

    return 0;
}
