/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <cstdio>

using namespace std;


int main() {

    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c) != EOF) {
        int d = a+b+c;
        if (d == 1) {
            if (a == 1) puts("A");
            else if (b == 1) puts("B");
            else puts("C");
        }
        else if (d == 2) {
            if (a == 0) puts("A");
            else if (b == 0) puts("B");
            else puts("C");
        }
        else puts("*");
    }

    return 0;
}
