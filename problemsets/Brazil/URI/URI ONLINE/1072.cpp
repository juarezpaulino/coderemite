/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int n, x;
    int in = 0, out = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x >= 10 && x <= 20) in++;
        else out++;
    }
    printf("%d in\n", in);
    printf("%d out\n", out);


    return 0;
}
