/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int N, P, Q;
    char c;

    scanf("%d %d %c %d", &N, &P, &c, &Q);
    bool ok = 1;
    if (c == '+') {
        if (P+Q > N) ok = 0;
    }
    else {
        if (P*Q > N) ok = 0;
    }
    printf("%s\n", ok ? "OK" : "OVERFLOW");

    return 0;
}
