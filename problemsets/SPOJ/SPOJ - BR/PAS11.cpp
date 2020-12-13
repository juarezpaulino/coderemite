/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {

    int N;
    int first = 1, r = 0, ret = 1, x, y;
    scanf("%d", &N);
    scanf("%d", &x);
    for (int i = 1; i < N; i++) {
        scanf("%d", &y);
        if (first) r = y-x, first = 0;
        else {
            if (y-x != r) {
                ret++;
                first = 1;
            }
        }
        x = y;
    }
    printf("%d\n", ret);

    return 0;
}
