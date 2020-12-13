/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;

int main() {

    int N;
    int id = 1;
    while (scanf("%d", &N) && N) {
        printf("Case %d: ", id++);
        int b = 0, c;
        for (int i = 0; i < N; i++) {
            scanf("%d", &c);
            if (c == 0) b--;
            else b++;
        }
        printf("%d\n", b);
    }

    return 0;
}
